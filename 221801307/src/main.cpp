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

	int CharNum = CountChars(argv[1]);
	int LineNum = CountLines(argv[1]);
	int WordNum = CountWords(argv[1]);

	printf("In this file:\n");
	printf("Number of characters: %d\n", CharNum);
	printf("Number of non-empty lines: %d\n", LineNum);
	printf("Number of words: %d\n", WordNum);

	printf("Top 10 words:\n");
	WordNums(argv[1]);

	auto TopWord = TopWords();
	OutputB(TopWord);

	fstream file;
	file.open("output.txt", ios::out);
	file << "characters: " << CharNum << endl;
	file << "words: " << LineNum << endl;
	file << "lines: " << WordNum << endl;
	file.close();

	OutputF(TopWord,argv[2]);
	return 0;
}