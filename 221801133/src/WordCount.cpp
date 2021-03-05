#include "countFile.h"
#include <iostream>
using namespace std;


int main(int argc,char* argv[]){
	
	countFile CF;
	//打开读写两文件 
	
	if (!argv[1] ) {
		cout << "Please enter read file!";
		return 0;
	}
	if(!argv[2]){
		cout << "Please enter write files";
		return 0;
	}
	ifstream in;
	in.open(argv[1]);
	string s=CF.getString(in);
	CF.loadMap(s);
	
	ofstream out;
	out.open(argv[2]);
	
	// 字符数和行数
	CF.countChara(s,out);
	CF.countWord(out);
	CF.countLine(s,out);
	vector<pair<int,string> > v=CF.getSort();
	for(int i=0;i<10;i++){
		out<<v[i].second<<": "<<v[i].first<<endl;
	}
	out.close();
	
	 
}
