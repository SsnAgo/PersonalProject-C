#include"pch.h"
#include"charNum.h"

int charNum(char * filename)//计算字符数，包括(空格，制表符，换行等)
{
	int count = 0;
	char c;
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "文件打开失败";
	}
	while ((c = file.get()) != EOF)
	{
	    count++;
	}
	file.close();
	return count;
}
