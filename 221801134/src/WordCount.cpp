#include <iostream>
#include "WordFile.h"

int main(int agrs, char* arg[])
{
	WordFile wf;
	wf.openInFile(arg[1]);
	wf.openOutFile(arg[2]);
	wf.getCharacters();
	wf.getWords();
	wf.getLines();
	wf.getWordsNum();

	return 0;
}
