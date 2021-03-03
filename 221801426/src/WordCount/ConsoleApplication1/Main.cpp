// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <regex>
#include <map>
#include <algorithm>
#include <unordered_map>
#define psi pair<string, int>
#define vpsi vector<psi>


using namespace std;

int CharCount(const char* filename);
int LinesCount(const char* filename);
int WordsCount(const char* filename);
void WordsPrint(const char* filename1, const char* filename2, int num);

int main(int argc, const char* argv[]) {
	const char* InputFileName = "input.txt";
	const char* OutputFileName = "result.txt";

	ifstream TextFile(InputFileName);
	if (!TextFile)
	{
		cout << "Erro!" << endl;
	}
	int charNum = CharCount(InputFileName);
	int linesNum = LinesCount(InputFileName);
	int wordsNum = WordsCount(InputFileName);

	ofstream out(OutputFileName);

	out << "characters:" << charNum << endl;
	out << "words:" << wordsNum << endl;
	out << "lines:" << linesNum << endl;
	WordsPrint(InputFileName, OutputFileName, 10);
	out.close();
	return 0;
}

int CharCount(const char* filename)
{
	int charNum = 0;
	ifstream ifs(filename);
	char c;

	while ((c = ifs.get()) != EOF)
	{
		if (c >= NULL && c <= '~')
			charNum++;
	}
	ifs.clear();
	ifs.seekg(0);
	return charNum;
}

int LinesCount(const char* filename)
{
	int i = 0;
	bool isNull = 1;
	int lines = 0;
	fstream fs(filename, ios::in);
	string s;
	while (getline(fs, s))
	{
		for (i = 0, isNull = 1; i < s.length(); i++)
		{
			if (s[i] != ' ' && s[i] != '\t')
			{
				isNull = 0;
				break;
			}
		}
		if (!isNull)
			lines++;
	}
	return lines;
}
int WordsCount(const char* filename)
{
	regex word("[A-Za-z][A-Za-z][A-Za-z][A-Za-z]([\\w]+)");
	int wordNum = 0;
	fstream fs;
	fs.open(filename);
	string str;
	while (fs >> str)
	{
		sregex_token_iterator end;
		for (sregex_token_iterator iter(str.begin(), str.end(), word), end; iter != end; iter++)
		{
			wordNum++;
		}
	}
	return wordNum;
}

int SortWords(psi p1, psi p2)
{
	if (p1.second == p2.second)
	{
		return p1.first < p2.first;//词频相等按字典序排列
	}
	else
		return p1.second > p2.second;
}
vpsi WordsVec;
void WordsFrequency(const char* filename)
{
	
	unordered_map<string, int> WordsMap;
	regex word("[A-Za-z][A-Za-z][A-Za-z][A-Za-z]([\\w]+)");//单词的正则表达式
	fstream fs;
	fs.open(filename);
	string str;
	while (fs >> str)//读入一行
	{
		transform(str.begin(),str.end(),str.begin(),::tolower);//转化为小写
		sregex_token_iterator end;
		for (sregex_token_iterator iter(str.begin(), str.end(), word), end; iter != end; iter++)
		{
			WordsMap[*iter]++;
		}
	}
	for (unordered_map<string, int>::iterator iter = WordsMap.begin(); iter != WordsMap.end(); iter++)
	{
		WordsVec.push_back(pair<string, int>(iter->first, iter->second));
	}
	sort(WordsVec.begin(), WordsVec.end(), SortWords);
	fs.clear();
	fs.seekg(0);
	fs.close();
}
void WordsPrint(const char* filename1, const char* filename2, int num)
{
	WordsFrequency(filename1);
	int count = WordsVec.size();
	count = (count < num) ? count : num;//判断词数是否小于10

	ofstream out(filename2, ios::in | ios::out);
	out.seekp(0, ios::end);
	for (vpsi::iterator iter = WordsVec.begin(); iter != (WordsVec.begin() + count); ++iter)
	{
		out << iter->first << ":" << iter->second << endl;
	}
}

