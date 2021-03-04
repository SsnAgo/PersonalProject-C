#pragma once
#include<fstream>
#include<iostream>
#include"AppData.h"
#include<unordered_map>
class TxtOutput
{
public:
	ofstream  out;
	TxtOutput(string filename)
	{
		out.open(filename, ios::out);
		if (!out.is_open())
		{
			cout << "打开文件失败！" << endl;
		}
	}
	void OutTxt(AppData* data)
	{
		out << "characters: " << data->number_asc << "\n";
		out << "words: " << data->number_words << "\n";
		out << "lines: " << data->number_line << "\n";
		unordered_map<string, int>::iterator it;
		for (it = data->words.begin(); it != data->words.end(); it++)
		{
			pair<string, int>temp = *it;
			out << temp.first + ": " << temp.second << "\n";
		}
	}
};

