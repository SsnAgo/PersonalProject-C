#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
ifstream infile;
ofstream outfile;
map<string, int> mword;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

//打开输入文件 
void openInFile(char in[]) {
	infile.open(in);
	if (!infile.is_open()) {
		cout << "Could not find the file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
}

//打开输出文件 
void openOutFile(char out[]) {
	outfile.open(out);
	if (!outfile.is_open()) {
		cout << "Could not find the file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
}

//统计文件的字符数（对应输出第一行）
void getCharacters() {
	int count = 0;
	char c;
	while ((c = infile.get()) != EOF) {
		//cout<<c;
		count++;
	}

	cout << endl << "characters:" << count << "\n\n";
	outfile << "characters:" << count << "\n";
	infile.clear();
	infile.seekg(0);
}

//判断是否是合法的单词 
bool isWord(char word[]) {
	if (strlen(word) < 4)
		return false;
	for (int i = 0;i < 4;i++)
		if (!isalpha(word[i]))
			return false;
	return true;
}

//统计文件的单词总数（对应输出第二行）
void getWords() {
	int numbers = 0;
	char data[1024];
	while (infile >> data) {
		//cout<<data<<endl; 
		//_strlwr_s(data); //vs下使用 
		strlwr(data);
		if (!isWord(data))
			continue;
		if (mword.find(data) == mword.end()) {
			mword[data] = 1;
			numbers++;
		}
		else
			mword[data]++;
	}

	cout << "words:" << numbers << "\n\n";
	outfile << "words:" << numbers << "\n";
	infile.clear();
	infile.seekg(0);
}

//统计文件的有效行数（对应输出第三行）
void getLines() {
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

	cout << "lines:" << count << "\n\n";
	outfile << "lines:" << count << "\n";
}

//统计文件中各单词的出现次数（对应输出接下来10行）
void getWordsNum() {
	int numbers = 0;

	vector< pair<string, int> > vec(mword.begin(), mword.end());
	//对线性的vector进行排序
	sort(vec.begin(), vec.end(), cmp);
	int len = 10;
	if (vec.size() < 10)
		len = vec.size();
	for (int i = 0;i < len;i++) {
		cout << vec[i].first << " : " << vec[i].second << endl;
		outfile << vec[i].first << ":" << vec[i].second << "\n";
	}
}

int main(int agrs, char* arg[]) {
	//cout<<arg[1]<<endl<<arg[2]<<endl;

	openInFile(arg[1]);//打开输入文件
	openOutFile(arg[2]);//打开输出文件 
	getCharacters();//统计文件的字符数（对应输出第一行）
	getWords();//统计文件的单词总数（对应输出第二行）
	getLines();//统计文件的有效行数（对应输出第三行）
	getWordsNum();//统计文件中各单词的出现次数（对应输出接下来10行）
}
