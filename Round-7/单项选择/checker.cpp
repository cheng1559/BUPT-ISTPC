#include "testlib.h"
#include <cctype>

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	std::string output;
	while (!ouf.eof()) {
		char ch = ouf.readChar();
		if (isalpha(ch)) {
			output += toupper(ch);
		}
	}
	int begin = ans.readInt(), end = ans.readInt();
	std::string answer = ans.readToken();
	for (int i = begin; i <= end; i++) {
		quitif((int)output.size() < i || output[i - 1] != answer[i - 1], _wa, "the participant's output is incorrect");
	}
	quitf(_ok, "the participant's output is correct");
	return 0;
}