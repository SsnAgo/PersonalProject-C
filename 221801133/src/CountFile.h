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
		
		countFile();
		//获得字符串 ，写入map 
		string getString(ifstream& in);
		void loadMap(string str,map<string,int>  mp); 
		
		//字符和行统计数 
		int countChar(string str);
		int countLine(string str);
		int countWord(map<string,int>  mp);
		//利用向量排序  
		void getSort(map<string,int>  mp);
		
		void writeFile(ofstream& out);
			
	private:
		int chars;
		int words;
		int lines;
		vector<pair<int, string> > v;
}; 
