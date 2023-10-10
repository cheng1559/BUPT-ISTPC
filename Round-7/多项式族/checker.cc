#include "common.hh"
#include "testlib.h"
#include <algorithm>
#include <cmath>

// Polyfill for std::optional.
class OptionalDouble {
  private:
	bool has_value;
	double value;

  public:
	OptionalDouble() : has_value(false) {}
	OptionalDouble(double value) : has_value(true), value(value) {}
	bool has() const { return has_value; }
	double get() const { return value; }
};

static OptionalDouble readAns(InStream &in) {
	std::string first_ans = upperCase(in.readToken());
	if (first_ans == "NO") {
		return OptionalDouble();
	} else if (first_ans == "YES") {
		return in.readReal();
	} else {
		quitf(_wa, "Invalid answer: %s", first_ans.c_str());
	}
}

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	OptionalDouble jury = readAns(ans), participant = readAns(ouf);
	if (jury.has() != participant.has()) {
		quitf(_wa, "Participant answered differently from jury");
	} else if (jury.has()) {
		double error = std::abs(jury.get() - participant.get()) / std::max(1.0, jury.get());
		if (!std::isfinite(participant.get()) || !std::isfinite(error)) {
			quitf(_wa, "Expected finite answer");
		} else if (error > 1e-6) {
			quitf(_wa, "Participant answered differently from jury");
		}
	}
	quitf(_ok, "Correct");
	return 0;
}