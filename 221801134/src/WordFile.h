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
	string getWordFile();

	int getCharacters(string str);
	int getWords(string str);
	int getLines(string str);

	void getWordsNum();
	bool isWord(string word);
private:
	ifstream infile;
	ofstream outfile;
	map<string, int> mword;
};
bool cmp(const pair<string, int>& a, const pair<string, int>& b);
vector<string> split(const string &s);
