#include "ParseArgs.h"

int ParseArgs(int argc, char **argv){
	if (argv[1] == NULL){
		printf("No input file name!\n");
		return -1;
	}
	if (argv[2] == NULL){
		printf("No output file name!\n");
		return -1;
	}
	std::fstream Ifile;
	Ifile.open(argv[1]);
	if (!Ifile){
		printf("Failed to open file: %s\n", argv[1]);
		return -1;
	}
	Ifile.close();

	std::fstream Ofile;
	Ofile.open(argv[1]);
	if (!Ofile) {
		printf("Failed to open file: %s\n", argv[2]);
		return -1;
	}
	Ofile.close();
	return 0;
}