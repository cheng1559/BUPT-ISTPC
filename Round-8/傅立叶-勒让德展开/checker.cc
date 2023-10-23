#include "testlib.h"
#include <math.h>

int main(int argc, char * argv[]) {
	registerTestlibCmd(argc, argv);
	double jury = ans.readReal();
	double contestant = ouf.readReal();
	if (std::abs(jury - contestant) / std::max(std::abs(jury), 1.0) <= 1e-6) {
		quitf(_ok, "Good job!");
	} else {
		quitf(_wa, "Expected %.6f, found %.6f", jury, contestant);
	}
}