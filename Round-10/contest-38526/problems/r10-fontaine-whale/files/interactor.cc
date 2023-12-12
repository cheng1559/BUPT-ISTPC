#include "testlib.h"
#include "common.hh"

int main(int argc, char *argv[]) {
	registerInteraction(argc, argv);

	// Read test case
	cave::DecimalFixed k = readDecimalFixed(inf);
	std::vector<cave::DecimalFixed> a;
	std::string interactor_log;
	while (!inf.seekEof()) {
		a.push_back(readDecimalFixed(inf));
	}
	Test t(Polynomial(a), k);

	// Interact
	long long count = 0;
	std::string k_output = k.to_string();
	std::cout << k_output << std::endl;
	interactor_log += "[Interactor] " + k_output + "\n"; 
	cave::DecimalFixed contestant_answer;
	while (1) {
		count++;
		std::string op = ouf.readToken();
		if (op == "!") {
			contestant_answer = readDecimalFixed(ouf);
	        interactor_log += "[Participant] ! " + contestant_answer.to_string() + "\n"; 
			break;
		} else if (op == "?") {
			cave::DecimalFixed x = readDecimalFixed(ouf);
	        interactor_log += "[Participant] ? " + x.to_string() + "\n"; 
	        std::string res = t(x).to_string();
			std::cout << res << std::endl;
        	interactor_log += "[Interactor] " + res + "\n"; 
		}
		if (count > 200) {
		    break;
		}
	}
	tout << count << " " << contestant_answer.to_string() << " " << (t.verify(contestant_answer) ? "ACCEPTED" : "REJECTED") << std::endl;
	tout << interactor_log;
	quitf(_ok, "OK");
	return 0;
}