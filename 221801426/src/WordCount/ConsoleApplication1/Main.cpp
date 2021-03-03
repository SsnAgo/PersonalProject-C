// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int CharCount(const char* filename);
int LinesCount(const char* filename);
int WordsCount(const char* filename);

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
	out.close();
	return 0;
}

int CharCount(const char* filename)
{
	int charNum = 0;
	ifstream ifs(filename);
	char charTemp;

	while ((charTemp = ifs.get()) != EOF)
	{
		if (charTemp >= NULL && charTemp <= '~')
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
	regex word("[A-Za-z][A-Za-z][A-Za-z][A-Za-z]([\\w]+)");//单词的正则表达式
	int wordNum = 0;
	fstream fs;
	fs.open(filename);
	string str;
	while (fs >> str)//读入一行
	{
		sregex_token_iterator end;
		for (sregex_token_iterator iter(str.begin(), str.end(), word), end; iter != end; iter++)
		{
			wordNum++;
		}
	}
	return wordNum;
}

