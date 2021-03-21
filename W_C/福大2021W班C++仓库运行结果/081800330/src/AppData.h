#pragma once
#ifndef APPDATA_H
#define APPDATA_H
#include<iostream>
#include<unordered_map>
using namespace std;
class AppData
{
public:
	static AppData singleton;
	int number_asc;//字符数
	int number_words;//单词数;
	int number_line;//行数
	unordered_map<string, int>words;
};
#endif

