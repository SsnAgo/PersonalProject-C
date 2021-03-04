#include "pch.h"
#include "wordFre.h"

map<string, int> Map;
void wordFre(char *filename)//频率最高的十个单词 
{
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "文件打开失败";
	}
	string s;
	regex r("\\b[a-zA-Z]{4}[a-zA-Z0-9]*", regex::icase);
	while (file >> s) 
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] <= 'Z'&&s[i] >= 'A')//不区分大小写，将所有大写字母变成小写
			{
				s[i] = s[i] + 32;
			}
		}
		smatch m;
		while (regex_search(s, m, r)) 
		{
			Map[m[0]]++;
			s = m.suffix().str();
		}
	}
	file.close();
}