#include "../lib/compiler.h"

/**
 * @param argc The index of flags 
 * @param argv The diffrent flags
 * 
 * @return The exit status for the compiler
 */
int compile(int argc, const char *argv[]) {
	if (argc < 3) {
		crash(1);
	} else if (argc > 3) {
		crash(2);
	}

	return 0;
}