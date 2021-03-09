#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<ctype.h>
#include<map>
#include<vector> 
#include<utility>
#include<algorithm>
using namespace std;
//定义类 

class countFile{
	public:
		string getString(ifstream& in);
		void loadMap(string str); 
		//字符和行统计数 
		void countChara(string str,ofstream& out);
		void countLine(string str,ofstream& out);
		void countWord(ofstream& out);
		//利用向量排序 
		vector<pair<int,string> > getSort();
	
	private:
		map<string,int>	mp;
		
}; 
