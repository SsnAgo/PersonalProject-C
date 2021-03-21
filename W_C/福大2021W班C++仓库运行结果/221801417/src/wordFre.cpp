#include "pch.h"
#include "wordFre.h"

map<string, int> Map;
void wordFre(char *filename)//Ƶ����ߵ�ʮ������ 
{
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "�ļ���ʧ��";
	}
	string s;
	regex r("\\b[a-zA-Z]{4}[a-zA-Z0-9]*", regex::icase);
	while (file >> s) 
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] <= 'Z'&&s[i] >= 'A')//�����ִ�Сд�������д�д��ĸ���Сд
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