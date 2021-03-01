// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<regex>
#include "charNum.h"
#include "lineNum.h"
#include "wordNum.h"
#include "wordFre.h"
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	bool result = false;
	if (a.second == b.second&&a.first < b.first)//若词频出现次数相等则按递增字典序输出
	{
		return true;
	}
	else if (a.second > b.second)
	{
		return true;
	}
	else
	{
		return result;
	}
}
int main(int argc,char** argv)
{
	int count = 10;
	ofstream fileOutput;
	char filename[105]= "input.txt";
	fileOutput.open("output.txt", ios::app);
	fileOutput << "characters: " << charNum(filename) << endl;
	fileOutput << "lines: " << lineNum(filename) << endl;
	fileOutput << "words: " << wordNum(filename) << endl;
	wordFre(filename);
	vector<pair<string, int> > vec;
	extern map<string, int> Map;
	for (auto u : Map) 
	{
		vec.push_back(u);
	}
	sort(vec.begin(), vec.end(), cmp);
	for (auto u : vec)
	{
		if (count)//输出频率最高的10个单词
		{
			fileOutput << "<" << u.first << ">" << ":" << " " << u.second << endl;
			count--;
		}
		else break;
	}
	return 0;
}

