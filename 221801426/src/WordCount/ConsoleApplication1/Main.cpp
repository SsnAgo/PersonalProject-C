// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int CharCount(const char* filename);

int main(int argc, const char* argv[]) {
	const char* InputFileName = "input.txt";
	const char* OutputFileName = "result.txt";

	ifstream TextFile(InputFileName);
	if (!TextFile)
	{
		cout << "Erro!" << endl;
	}
	long CharNum = CharCount(InputFileName);
	ofstream out(OutputFileName);
	out << "characters:" << CharNum << endl;
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

