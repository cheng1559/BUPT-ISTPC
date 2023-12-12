#include "testlib.h"
#include "common.hh"
#include <vector>

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	// This is input for interactor, not for participant's program, so relax. :)
	inf.strict = false;
	cave::DecimalFixed k = readDecimalFixed(inf);
	quitif(k < 1 || k > 100, _fail, "k");
	std::vector<cave::DecimalFixed> a;
	while (!inf.seekEof()) {
		a.push_back(readDecimalFixed(inf));
	}
	Test t(Polynomial(a), k);
	inf.readEof();
	std::cerr << "OK, expect awswer " << t.answer().to_string().c_str() << std::endl;
	return 0;
}