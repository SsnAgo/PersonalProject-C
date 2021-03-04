// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Lib.h"

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
