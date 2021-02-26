#include <iostream>
#include "WordFile.h"

int main(int agrs, char* arg[])
{
	if (agrs< 3) {
		cout << "Please input and output files!";
		return 0;
	}
		
	WordFile wf;
	if (!wf.openInFile(arg[1])) {
		cout << "Could not find the file!";
		return 0;
	}
	wf.openOutFile(arg[2]);
	wf.getCharacters();
	wf.getWords();
	wf.getLines();
	wf.getWordsNum();

	return 0;
}
