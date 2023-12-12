#include "testlib.h"

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	inf.readLong(1ll, 1'000'000'000'000'000ll, "k");
	inf.readEoln();
	inf.readEof();
	return 0;
}