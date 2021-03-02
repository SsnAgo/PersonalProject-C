#include "CountWords.h"

int Transition(int state, char input, int *count){
	switch (state){
	case OUTWORD:
		if (Separator(input)) return OUTWORD;
		if (isalpha(input)) return A;
		if (IsNum(input)) return NoWord;

	case NoWord:
		if (Separator(input)) return OUTWORD;
		else return NoWord;

	case A:
		if (IsNum(input)) return NoWord;
		if (isalpha(input)) return B;
		else return OUTWORD;

	case B:
		if (IsNum(input)) return NoWord;
		if (isalpha(input)) return C;
		else return OUTWORD;

	case C:
		if (IsNum(input)) return NoWord;
		if (isalpha(input)) return WORD;
		else return OUTWORD;

	case WORD:
		if (isalnum(input)) return WORD;
		else { (*count)++; return OUTWORD; }
	}
	return ERROR;
}

int CountWords(char *filename){
	int words = 0;
	char c;
	std::fstream file;
	file.open(filename, std::ios::in);
	int state = OUTWORD;
	while (file.get(c) && state != ERROR){
		c = tolower(c);
		state = Transition(state, c, &words);
	}
	if (state == ERROR){
		std::cout << "error state." << std::endl;
	}
	if (state == WORD){
		words++;
	}
	return words;
}