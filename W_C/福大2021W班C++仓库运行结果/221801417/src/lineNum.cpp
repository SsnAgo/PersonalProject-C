#include "pch.h"
#include "lineNum.h"
using namespace std;

int lineNum(char *filename)//������Ч����
{
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "�ļ���ʧ��";
	}
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