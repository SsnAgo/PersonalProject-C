#include "pch.h"
#include "wordNum.h"
using namespace std;

int wordNum(char * filename)//������������ĵ�������
{
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "�ļ���ʧ��";
	}
	int count = 0;
	string s;
	regex r("\\b[a-zA-Z]{4}[a-zA-Z0-9]*", regex::icase);
	while (file >> s) 
	{
		smatch m;
		while (regex_search(s, m, r)) //��������������ʽ�ĵ���
	    {
			count++;
			s = m.suffix().str();
		}
	}
	file.close();

	return count;
}