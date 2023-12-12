#include "testlib.h"

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	long long cnt = ouf.readLong(1, 1000000000000, "round");
	std::string ans = ouf.readToken("-?[0-9]+.?[0-9]*", "ans");
	std::string interactor_verdict = ouf.readToken("ACCEPTED|REJECTED", "interactor verdict");
	while (!ouf.seekEof()) {
		ouf.nextLine();
	}
	quitif(interactor_verdict == "REJECTED", _wa, "Participant answered %s, rejected by interactor", ans.c_str());
	quitif(cnt <= 100, _ok, "Participant answered %s in %lld interactions", ans.c_str(), cnt);
	int discount = std::max(0ll, 181 - cnt) / 10;
	quitp(discount * 10, "Participant answered %s in %lld interactions, discount %d%%", ans.c_str(), cnt, discount);
	return 0;
}