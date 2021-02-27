#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
typedef struct {
	string word;
	int num;
}words;
vector<words> v;
void wordsort(){
	for(int i = 0;i < v.size()-1;i++){
		for(int j = i+1;j < v.size();j++){
			if(v[i].num < v[j].num){
				words temp;
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}else if(v[i].num == v[j].num){
				if(v[i].word.compare(v[j].word) > 0){
					words temp;
					temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
			
		}
	}
} 
int countLetter(char* inter){
	ifstream fin(inter);
	if (!fin) {
		cout << "无法打开文件" << inter;
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
int countWord(char* inter){
	ifstream fin(inter);
	if (!fin) {
		cout << "无法打开文件" << inter;
		return 0;
	}
	string s; 
	string aword="";
	int word = 0;
	int isfirst = 1;
	int letters = 0;
	while (getline(fin,s)){
		for(int i = 0;i < s.size();i++){
			if((s[i] >= 'A'&&s[i] <= 'Z')||(s[i] >= 'a'&&s[i] <= 'z')||(s[i] <= '9'&&s[i] >= '0')){
				if(isfirst == 1){
					isfirst = 0;
					while((s[i] >= 'A'&&s[i] <= 'Z')||(s[i] >= 'a'&&s[i] <= 'z')){
						if(isupper(s[i])){
							s[i] = tolower(s[i]);
						}
						aword.append(1,s[i]);
						letters ++;
						i++;
					}
					while((s[i] >= 'A' &&s [i]<='Z')||(s[i] >= 'a'&&s[i] <= 'z')||(s[i] <= '9'&&s[i] >= '0')){
						if(isupper(s[i])){
							s[i] = tolower(s[i]);
						}
						aword.append(1,s[i]);
						i++;
					}
					if(letters >= 4){
						word++;
						int ishave = 0;
						for(int j = 0;j < v.size();j++){
							if(v[j].word == aword){
								ishave = 1;
								v[j].num++;
							}
						}
						if(ishave == 0){
							words newword;
							newword.word = aword;
							newword.num = 1;
							v.push_back(newword);
						}
					}
					isfirst = 1;
					letters = 0;
					aword = "";
				}
			}
		}
	}
	fin.close();
	return word;
}
int countRow(char* inter){
	ifstream fin(inter);
	if (!fin) {
		cout << "无法打开文件" << inter;
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
	
	int count = countLetter(argv[1]);
	int word = countWord(argv[1]);
	int rows = countRow(argv[1]);
	ofstream out(argv[2]);
	if(!out){
		cout << "无法打开文件";
		exit(1); 
    }
	out << "characters: " << count << '\n';
	out << "words: " << word << '\n';
	out << "lines: " <<rows << '\n';
	wordsort();
	for(int i = 0;(i < v.size()&&i < 10);i++){
		out << "words" << i+1 << ": " << v[i].num << '\n';
	}
}

