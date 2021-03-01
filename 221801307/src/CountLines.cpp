#include "CountLines.h"

int CountLines(char *filename){
	int lines = 0;
	char c;
	std::fstream file;
	file.open(filename);
	int state = EMPTY;  //当前行为空
	while (file.get(c)){
		if (state == EMPTY && !isspace(c)){
			state = NOTEMPTY;
		}
		if (c == '\n' && state == NOTEMPTY){
			lines++;
			state = EMPTY;
		}
	}
	if (state == NOTEMPTY){
		lines++;
	}
	return lines;
}