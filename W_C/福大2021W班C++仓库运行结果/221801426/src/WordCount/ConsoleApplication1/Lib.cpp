#include "Lib.h"

int CharCount(const char* filename)//ͳ���ַ���
{
	int charNum = 0;
	ifstream ifs(filename);
	char c;

	while ((c = ifs.get()) != EOF)
	{
		if (c >= NULL && c <= '~')
			charNum++;
	}
	ifs.clear();
	ifs.seekg(0);
	return charNum;
}

int LinesCount(const char* filename)//ͳ������
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

int WordsCount(const char* filename)//ͳ�Ƶ�����
{
	regex word("[A-Za-z][A-Za-z][A-Za-z][A-Za-z]([\\w]+)");//���ʵ�������ʽ
	int wordNum = 0;
	fstream fs;
	fs.open(filename);
	string str;
	while (fs >> str)
	{
		sregex_token_iterator end;
		for (sregex_token_iterator iter(str.begin(), str.end(), word), end; iter != end; iter++)
		{
			wordNum++;
		}
	}
	return wordNum;
}

int SortWords(psi p1, psi p2)//����
{
	if (p1.second == p2.second)
	{
		return p1.first < p2.first;//��Ƶ��Ȱ��ֵ�������
	}
	else
		return p1.second > p2.second;
}

vpsi WordsVec;
void WordsFrequency(const char* filename)
{

	unordered_map<string, int> WordsMap;
	regex word("[A-Za-z][A-Za-z][A-Za-z][A-Za-z]([\\w]+)");//���ʵ�������ʽ
	fstream fs;
	fs.open(filename);
	string str;
	while (fs >> str)//����һ��
	{
		transform(str.begin(), str.end(), str.begin(), ::tolower);//ת��ΪСд
		sregex_token_iterator end;
		for (sregex_token_iterator iter(str.begin(), str.end(), word), end; iter != end; iter++)
		{
			WordsMap[*iter]++;
		}
	}
	for (unordered_map<string, int>::iterator iter = WordsMap.begin(); iter != WordsMap.end(); iter++)
	{
		WordsVec.push_back(pair<string, int>(iter->first, iter->second));
	}
	sort(WordsVec.begin(), WordsVec.end(), SortWords);
	fs.clear();
	fs.seekg(0);
	fs.close();
}

void WordsPrint(const char* filename1, const char* filename2, int num)//��ӡ����
{
	WordsFrequency(filename1);
	int count = WordsVec.size();
	count = (count < num) ? count : num;//�жϴ����Ƿ�С��10

	ofstream out(filename2, ios::in | ios::out);
	out.seekp(0, ios::end);
	for (vpsi::iterator iter = WordsVec.begin(); iter != (WordsVec.begin() + count); ++iter)
	{
		out << iter->first << ": " << iter->second << endl;
	}
}
