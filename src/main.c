#include <stdio.h>

// Nevz
#include "include/utils.h"


int main(int argc, const char* argv[]) {
	if (argc < 2) {
		error(1);
	} else if (argc > 2) {
		error(2);
	}

	return 0;
}