#include "testlib.h"
#include <algorithm>
#include <map>
#include <optional>
#include <string>
#include <tuple>
#include <sys/random.h>

struct Func {
	static std::map<int, std::vector<Func>> existing;
	int ret;
	std::vector<int> args;

	bool operator<(const Func &rhs) const { return std::tie(ret, args) < std::tie(rhs.ret, rhs.args); }
	static Func random(int ret, int maxtype) {
		std::vector<Func> &existing = Func::existing[ret];
		if (!existing.empty() && rnd.next(0, 5) < (int)existing.size()) {
			return existing[rnd.next(0, (int)existing.size() - 1)];
		}
		int l = rnd.next(0, 5);
		if (rnd.next(0, 2) == 0) {
			l = std::min(l, 2);
		}
		int argc = rnd.next(0, 1 << l);
		Func func;
		func.ret = ret;
		for (int i = 0; i < argc; i++) {
			func.args.push_back(rnd.next(1, maxtype));
		}
		existing.push_back(func);
		return func;
	}

	static Func contant(int ret) {
		Func func;
		func.ret = ret;
		return func;
	}
	Func() {}
};

std::map<int, std::vector<Func>> Func::existing;

struct Expr {
	std::optional<Expr *> void_expr;
	Func func;
	std::vector<Expr *> args;

	static Expr *random(int type, int max_depth, int max_type) {
		if (max_depth == 0) {
			Expr *expr = new Expr();
			expr->func = Func::contant(type);
			return expr;
		}
		Expr *expr = new Expr();
		int attach_void = rnd.next(0, 1);
		if (attach_void) {
			expr->void_expr = Expr::random(0, max_depth - 1, max_type);
		}
		expr->func = Func::random(type, max_type);
		for (int arg : expr->func.args) {
			expr->args.push_back(Expr::random(arg, max_depth - 1, max_type));
		}
		return expr;
	}

	void serialize(std::vector<int> &asm_, std::map<Func, int> &id, int &line, std::vector<int> &main_args, int &stack) {
		if (func.args.empty() && func.ret && stack == 0) {
			main_args.push_back(func.ret);
			stack++;
			return;
		}
		if (void_expr) {
			(*void_expr)->serialize(asm_, id, line, main_args, stack);
		}
		for (Expr *arg : args) {
			arg->serialize(asm_, id, line, main_args, stack);
		}
		if (id.count(func)) {
			asm_.push_back(id[func]);
			line++;
		} else {
			int new_id = id.size() + 1;
			id[func] = new_id;
			asm_.push_back(id[func]);
			line++;
		}
		stack -= func.args.size();
		if (func.ret) {
			stack++;
		}
	}

	~Expr() {
		if (void_expr) {
			delete *void_expr;
		}
		for (Expr *arg : args) {
			delete arg;
		}
	}
};

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);

	int make_no = rnd.next(0, 1);

	// int system_random;
	// getrandom(&system_random, sizeof(system_random), 0);
	// rnd.setSeed(system_random);
	
	int ret = rnd.next(0, 200);
	Expr *expr = Expr::random(ret, 5, 200);
	std::vector<int> body;
	std::map<Func, int> id;
	std::vector<int> main_args;
	int body_line = 0;
	int stack;
	expr->serialize(body, id, body_line, main_args, stack);
	std::cout << id.size();
	std::vector<Func> inv(id.size());
	for (auto &[func, id] : id) {
		inv[id - 1] = func;
	}
	for (auto &func : inv) {
		std::cout << std::endl << func.ret << " " << func.args.size();
		for (int arg : func.args) {
			std::cout << " " << arg;
		}
	}
	std::reverse(main_args.begin(), main_args.end());
	bool make_no_in_args = rnd.next(0, 2) == 0 && !main_args.empty();
	if (make_no_in_args) {
		main_args[rnd.next(0, (int)main_args.size() - 1)] = rnd.next(1, 200);
	}
	bool make_no_in_ret = make_no && rnd.next(0, 1);
	if (make_no_in_ret) {
		ret = rnd.next(1, 200);
	}
	bool make_no_in_body = make_no && !make_no_in_args && !make_no_in_ret;
	if (make_no_in_body) {
		body[rnd.next(0, (int)body.size() - 1)] = rnd.next(1, (int)inv.size());
	}
	if (make_no && !make_no_in_body && !body.empty()) {
		body.pop_back();
		body_line--;
	}
	std::cout << std::endl << body_line << " " << ret << " " << main_args.size();
	for (int arg : main_args) {
		std::cout << " " << arg;
	}
	for (int line : body) {
		std::cout << std::endl << line;
	}
	delete expr;
	return 0;
}