#include "common.hh"

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	clock_t start = clock();

	// Before judging, validate the input loosely.
	int k = inf.readInt(1, INPUT_MAX_LEN);
	inf.readEoln();
	std::vector<uint32_t> n(k);
	for (auto &v : n) {
		v = inf.readInt(2, INPUT_MAX_VAL);
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

	// Read the output.
	int l = ouf.readInt(1, OUTPUT_MAX_LEN, "the output sequence length");
	ouf.readEoln();
	std::vector<uint32_t> m(l);
	for (auto &v : m) {
		v = ouf.readInt(2, OUTPUT_MAX_VAL, "the output sequence element");
	}

	// Constraint #1: The sequence is strictly increasing.
	for (int i = 1; i < l; i++) {
		quitif(m[i] <= m[i - 1], _wa, "The output is not strictly increasing.");
	}

	// Constraint #2: The output is not identical to the input.
	quitif(n == m, _wa, "The output is identical to the input, which is not allowed.");

	// Constraint #3: The output sequence represents the same number as the input sequence.
	cave::BigUnsigned output_numerator, output_denominator = {1};
	for (int i = 0; i < l; i++) {
		// new output = output + 1 / m[i]
		cave::b_mul(output_numerator, {m[i]});
		cave::b_add(output_numerator, output_denominator);
		cave::b_mul(output_denominator, {m[i]});
	}
	// Verify that the output is the same as the input.
	cave::b_mul(output_numerator, input_denominator);
	cave::b_mul(input_numerator, output_denominator);
	int ord = cave::b_cmp(output_numerator, input_numerator);
	quitif(ord > 0, _wa, "The output is greater than the input.");
	quitif(ord < 0, _wa, "The output is less than the input.");


	// Okay, the output is correct.
	clock_t end = clock();
	quitf(_ok, "The output is a different sequence representing the same number as the input. Checked in %.3f seconds.", (double)(end - start) / CLOCKS_PER_SEC);
}