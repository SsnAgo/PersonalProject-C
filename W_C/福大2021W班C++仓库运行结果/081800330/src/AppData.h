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
	int number_asc;//�ַ���
	int number_words;//������;
	int number_line;//����
	unordered_map<string, int>words;
};
#endif

