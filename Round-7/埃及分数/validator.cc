#include "common.hh"

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	int k = inf.readInt(1, INPUT_MAX_LEN);
	inf.readEoln();
	std::vector<uint32_t> n(k);
	for (int i = 0; i < k; i++) {
		n[i] = inf.readInt(2, INPUT_MAX_VAL);
		if (i != k - 1) {
			inf.readSpace();
		} else {
			inf.readEof();
		}
	}
	for (int i = 1; i < k; i++) {
		quitif(n[i] <= n[i - 1], _fail, "Invalid input");
	}
	cave::BigUnsigned input_numerator, input_denominator = {1};
	for (int i = 0; i < k; ++i) {
		// new input = input + 1 / n[i]
		cave::b_mul(input_numerator, {n[i]});
		cave::b_add(input_numerator, input_denominator);
		cave::b_mul(input_denominator, {n[i]});
	}
	quitif(cave::b_cmp(input_numerator, input_denominator) >= 0, _fail, "Invalid input");
	return 0;
}