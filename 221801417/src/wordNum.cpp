#include "pch.h"
#include "wordNum.h"
using namespace std;

int wordNum(char * filename)//计算符合条件的单词总数
{
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "文件打开失败";
	}
	int count = 0;
	string s;
	regex r("\\b[a-zA-Z]{4}[a-zA-Z0-9]*", regex::icase);
	while (file >> s) 
	{
		smatch m;
		while (regex_search(s, m, r)) //搜索符合正则表达式的单词
	    {
			count++;
			s = m.suffix().str();
		}
	}
	file.close();

	return count;
}