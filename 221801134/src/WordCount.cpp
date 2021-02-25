#include <iostream>
#include "WordFile.h"

int main(int agrs, char* arg[])
{
	WordFile wf;
	if(!wf.openInFile(arg[1]))
		exit(EXIT_FAILURE);
	wf.openOutFile(arg[2]);
	wf.getCharacters();
	wf.getWords();
	wf.getLines();
	wf.getWordsNum();

	return 0;
}
