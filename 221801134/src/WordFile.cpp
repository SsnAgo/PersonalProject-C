#include "WordFile.h"

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

//打开输入文件 
bool WordFile::openInFile(char in[]) {
	infile.open(in);
	if (!infile.is_open())
		return false;
	return true;
}

//打开输出文件 
bool WordFile::openOutFile(char out[]) {
	outfile.open(out);
	return true;
}

//统计文件的字符数（对应输出第一行）
int WordFile::getCharacters() {
	int count = 0;
	char c;
	while ((c = infile.get()) != EOF) {
		//cout<<c;
		count++;
	}

	cout << "characters:" << count << "\n";
	outfile << "characters:" << count << "\n";
	infile.clear();
	infile.seekg(0);
	return count;
}

//判断是否是合法的单词 
bool WordFile::isWord(char word[]) {
	if (strlen(word) < 4)
		return false;
	for (int i = 0;i < 4;i++)
		if (!isalpha(word[i]))
			return false;
	return true;
}

int WordFile::getWords() {
	int numbers = 0;
	char data[1024];
	while (infile >> data) {
		//cout<<data<<endl; 
		_strlwr_s(data);//VS下
		//strlwr(data);
		if (!isWord(data))
			continue;
		numbers++;
		if (mword.find(data) == mword.end()) 
			mword[data] = 1;
		else
			mword[data]++;
	}

	cout << "words:" << numbers << "\n";
	outfile << "words:" << numbers << "\n";
	infile.clear();
	infile.seekg(0);
	return numbers;
}

//统计文件的有效行数（对应输出第三行）
int WordFile::getLines() {
	int count = 0;
	string str;
	while (getline(infile, str, '\n')) {
		string blanks("\f\v\r\t\n ");
		str.erase(0, str.find_first_not_of(blanks));
		str.erase(str.find_last_not_of(blanks) + 1);
		if (str.length() > 0) {
			count++;
			//cout<<str<<endl;
		}
	}

	cout << "lines:" << count << "\n";
	outfile << "lines:" << count << "\n";
	return count;
}

//统计文件中各单词的出现次数（对应输出接下来10行）
void WordFile::getWordsNum() {
	vector< pair<string, int> > vec(mword.begin(), mword.end());
	//对线性的vector进行排序
	sort(vec.begin(), vec.end(), cmp);
	int len = 10;
	if (vec.size() < 10)
		len = vec.size();
	for (int i = 0;i < len;i++) {
		cout << vec[i].first << ":" << vec[i].second << endl;
		outfile << vec[i].first << ":" << vec[i].second << "\n";
	}
}
