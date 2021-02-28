#include "pch.h"
#include "lineNum.h"
using namespace std;

int lineNum(char *filename)//计算有效行数
{
	ifstream file;
	file.open(filename);
	int count = 0;
	string s;
	while (getline(file, s))
	{
		if (s != "\0")
		{
			count++;
		}
	}
	file.close();
	return count;
}