#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int countLetter(string txt){
	ifstream fin("inter.txt");
	if (!fin) {
		cout << "无法打开文件" << txt;
		return 0;
	}
	string s; 
	int count = 0;
	while (getline(fin, s)) {
		
		count += s.size();
	}
	fin.close();
	return count;
}
int countWord(string txt){
	ifstream fin("inter.txt");
	if (!fin) {
		cout << "无法打开文件" << txt;
		return 0;
	}
	string s; 
	int words = 0;
	int isfirst = 1;
	int letters = 0;
	while (getline(fin,s)){
		for(int i = 0;i < s.size();i++){
			if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]<='9'&&s[i]>='0')){
				if(isfirst == 1){
					isfirst = 0;
					while((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
						letters ++;
						i++;
					}
					while((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]<='9'&&s[i]>='0')){
						i++;
					}
					if(letters >= 4){
						words++;
					}
					isfirst = 1;
					letters = 0;
				}
			}
		}
	}
	fin.close();
	return words;
}
int countRow(string txt){
	ifstream fin("inter.txt");
	if (!fin) {
		cout << "无法打开文件" << txt;
		return 0;
	}
	int rows = 0;
	int isnull = 1;
	string s;
	while (getline(fin,s)){
		for(int i = 0;i < s.size();i++){
			if(s[i] != ' '){
				isnull = 0;
			}
		}
		if(isnull == 0){
			rows++;
			isnull = 1;
		}
	}
	fin.close();
	return rows;
}
int main(int argc, char* argv[]) {
	/*
	int count = countLetter("inter.txt");
	int words = countWord("inter.txt");
	int rows = countRow("inter.txt");
	cout << "字符数为：" << count << endl;
	cout << "单词数为：" << words << endl;
	cout << "行数为：" <<rows ;
	*/
	cout << argv[1] <<endl;
	cout << argv[2];
}

