#pragma once
#include<fstream>
#include<iostream>
#include"AppData.h"
#include<unordered_map>
#include<algorithm>
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
	static bool cmp(pair<string, int>&p1, pair<string,int>&p2)
	{
		return p1.first < p2.first;
	}
	void OutTxt(AppData* data)
	{
		out << "characters: " << data->number_asc << "\n";
		out << "words: " << data->number_words << "\n";
		out << "lines: " << data->number_line << "\n";
		vector<pair<string, int>>::iterator it;
		vector<pair<string, int>> all(data->words.begin(), data->words.end());
		sort(all.begin(), all.end(), TxtOutput::cmp);
		for (it = all.begin(); it != all.end(); it++)
		{
			pair<string, int>temp = *it;
			out << temp.first + ": " << temp.second << "\n";
		}
	}
};

