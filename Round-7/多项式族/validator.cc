#include "common.hh"
#include "testlib.h"

int main(int argc, char *argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(0, MAX_ORDER, "n");
	for (int i = 0; i <= n; i++) {
		inf.readEoln();
		inf.readInt(-MAX_ABS_X, MAX_ABS_X, "x_f_i");
		inf.readSpace();
		inf.readInt(-MAX_ABS_Y, MAX_ABS_Y, "y_f_i");
	}
	for (int i = 0; i <= n; i++) {
		inf.readEoln();
		inf.readInt(-MAX_ABS_X, MAX_ABS_X, "x_g_i");
		inf.readSpace();
		inf.readInt(-MAX_ABS_Y, MAX_ABS_Y, "y_g_i");
	}
	inf.readEof();
	return 0;
}