// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int CharCount(const char* filename);
int LinesCount(const char* filename);

int main(int argc, const char* argv[]) {
	const char* InputFileName = "input.txt";
	const char* OutputFileName = "result.txt";

	ifstream TextFile(InputFileName);
	if (!TextFile)
	{
		cout << "Erro!" << endl;
	}
	int CharNum = CharCount(InputFileName);
	int LinesNum = LinesCount(InputFileName);

	ofstream out(OutputFileName);

	out << "characters:" << CharNum << endl;
	out << "lines:" << LinesNum << endl;
	out.close();
	return 0;
}

int CharCount(const char* filename)
{
	int CharNum = 0;
	ifstream ifs(filename);
	char charTemp;

	while ((charTemp = ifs.get()) != EOF)
	{
		if (charTemp >= NULL && charTemp <= '~')
			CharNum++;
	}
	ifs.clear();
	ifs.seekg(0);
	return CharNum;
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

