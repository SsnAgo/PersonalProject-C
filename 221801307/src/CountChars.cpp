#include "CountChars.h"

int CountChars(char *filename){
	int chars = 0;
	char c;
	std::fstream file;
	file.open(filename, std::ios::in);
	while (file.get(c)){
		chars++;
	}
	file.close();
	return chars;
}