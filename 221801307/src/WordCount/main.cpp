#include<iostream>
#include<fstream>
#include"ParseArgs.h"
#include"CountChars.h"
#include"CountLines.h"
#include"CountWords.h"
#include"Word.h"

using namespace std;
int main(int argc, char **argv){
	int ret = ParseArgs(argc, argv);
	if (ret == -1) {
		return -1;
	}

	int numberOfChar = CountChars(argv[1]);
	int numberOfLines = CountLines(argv[1]);
	int numberOfWords = CountWords(argv[1]);

	printf("In this file:\n");
	printf("Number of characters: %d\n", numberOfChar);
	printf("Number of non-empty lines: %d\n", numberOfLines);
	printf("Number of words: %d\n", numberOfWords);

	printf("Top 10 words:\n");
	WordFrequency(argv[1]);

	auto topTenWordList = TopTenWords();
	StandardOutput(topTenWordList);

	fstream file;
	file.open("output.txt", ios::out);
	file << "characters: " << numberOfChar << endl;
	file << "words: " << numberOfWords << endl;
	file << "lines: " << numberOfLines << endl;
	file.close();

	OutputToFile(topTenWordList,argv[2]);
	return 0;
}