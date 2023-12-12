#include "testlib.h"

static const std::string YES = "YES";
static const std::string NO = "NO";

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	std::string jans_yesno = upperCase(ans.readWord("[a-zA-Z]+", "yesno"));
	std::string pans_yesno = upperCase(ouf.readWord("[a-zA-Z]+", "yesno"));
	if (jans_yesno != YES && jans_yesno != NO) {
		quitf(_fail, "Answer must be YES or NO, but %s", jans_yesno.c_str());
	}
	if (pans_yesno != YES && pans_yesno != NO) {
		quitf(_wa, "Participant's solution must be YES or NO, but %s", pans_yesno.c_str());
	}
	if (pans_yesno == NO && jans_yesno == YES) {
		quitf(_wa, "Jury finds a solution, but participant doesn't");
	}
	if (pans_yesno == YES && jans_yesno == NO) {
		quitf(_wa, "The question has no solution, but participant claims it has");
	}
	if (pans_yesno == YES) {
		for (int i = 1; i < n; i++) {
			int ja = ans.readInt(2, n, "c");
			int pa = ouf.readInt(2, n, "c");
			if (ja != pa) {
				quitf(_wa, "The %d-th number is %d, but participant claims it is %d", i, ja, pa);
			}
		}
	}
	quitf(_ok, "OK, participant's solution is correct");
	return 0;
}