#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class WordFile {
public:
	bool openInFile(char in[]);
	bool openOutFile(char out[]);
	int getCharacters();
	int getWords();
	int getLines();
	void getWordsNum();
	bool isWord(char word[]);
private:
	ifstream infile;
	ofstream outfile;
	map<string, int> mword;
};
bool cmp(const pair<string, int>& a, const pair<string, int>& b);