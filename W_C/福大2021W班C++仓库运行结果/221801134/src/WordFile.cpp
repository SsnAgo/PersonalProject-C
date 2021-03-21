#include "WordFile.h"

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

//�������ļ� 
bool WordFile::openInFile(char in[]) {
	infile.open(in);
	if (!infile.is_open())
		return false;
	return true;
}

//������ļ� 
bool WordFile::openOutFile(char out[]) {
	outfile.open(out);
	return true;
}

//ͳ���ļ����ַ�������Ӧ�����һ�У�
int WordFile::getCharacters(string str) {
	outfile << "characters: " << str.length() << "\n";
	return str.length();
}

//�ж��Ƿ��ǺϷ��ĵ��� 
bool WordFile::isWord(string word) {
	if (word.length() < 4)
		return false;
	for (int i = 0; i < 4; i++)
		if (!isalpha(word[i]))
			return false;
	return true;
}

int WordFile::getWords(string str) {
	int numbers = 0;
	vector<string> vec = split(str);
	for (vector<string>::iterator ite = vec.begin(); ite != vec.end(); ++ite) {
		string data;
		for (int i = 0; i < ite->size(); i++) 
			data += tolower((*ite)[i]);
		if (!isWord(data))
			continue;
		numbers++;
		if (mword.find(data) == mword.end())
			mword[data] = 1;
		else
			mword[data]++;
	}
		
	outfile << "words: " << numbers << "\n";
	return numbers;
}

//ͳ���ļ�����Ч��������Ӧ��������У�
int WordFile::getLines(string str) {
	int count = 0;
	string s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '\n') 
			s += str[i];
		else {
			string blanks("\f\v\r\t\n ");
			s.erase(0, s.find_first_not_of(blanks));
			s.erase(s.find_last_not_of(blanks) + 1);
			if (s.length() > 0) 
				count++;
			s = "";
		}
	}
	if (s != "") {
		string blanks("\f\v\r\t\n ");
		s.erase(0, s.find_first_not_of(blanks));
		s.erase(s.find_last_not_of(blanks) + 1);
		if (s.length() > 0) 
			count++;
	}

	outfile << "lines: " << count << "\n";
	return count;
}

//ͳ���ļ��и����ʵĳ��ִ�������Ӧ���������10�У�
void WordFile::getWordsNum() {
	vector< pair<string, int> > vec(mword.begin(), mword.end());
	//�����Ե�vector��������
	sort(vec.begin(), vec.end(), cmp);
	int len = 10;
	if (vec.size() < 10)
		len = vec.size();
	for (int i = 0; i < len; i++) 
		outfile << vec[i].first << ": " << vec[i].second << "\n";
}

vector<string> split(const std::string &s) {
	vector<string> vec_ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		while (i != s.size() && isspace(s[i]))// ignore the space 
			++i;
		string_size j = i;

		while (j != s.size() && !isspace(s[j]))// get all the char  
			++j;

		if (i != j) {
			vec_ret.push_back(s.substr(i, j - i));
			i = j;
		}
	} 
	return vec_ret;
}

string WordFile::getWordFile() {
	char c;
	string s;
	while ((c = infile.get()) != EOF)
		s += c;
	return s;
}
