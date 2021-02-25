#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	ifstream fin("inter.txt");
	if (!fin) {
		cout << "无法打开文件inter.txt";
	}
	string s; 
	int count = 0;
	while (getline(fin, s)) {
		count += s.size();
	}
	cout << "字符数为：" << count;
}
