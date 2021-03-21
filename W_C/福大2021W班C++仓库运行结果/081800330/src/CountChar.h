#pragma once
#ifndef COUNTCHAR_H
#define COUNTCHAR_H
#include<iostream>
#include"AppData.h"
#include<algorithm>
using namespace std;
class CountChar
{
public:	
	
	CountChar()
	{
	};

	 static  bool countChar(string s,AppData *data)
	{
		 string temp = "";
		 data->number_asc += s.length();
		 if (CountChar::isEmptyLine(s))
		 {
			 data->number_line--;
			 return 0;
		 }
		 for (int i = 0; i <= s.length(); i++)
		 {
			 if (i == s.length()||(!CountChar::numebr_letter(s[i]) && temp.length()) )
			 {
				 transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
				 if (CountChar::isWord(temp))
				 {
					 data->number_words++;
					 data->words[temp]++;
					 //cout << "得到字母:" << temp << endl;
					 
				 }
				 temp = "";
				 continue;
			 }
			 temp += s[i];
		 }
		// cout << "得到字符串:" << s << endl;
		 return 0;
	}
	 static bool isEmptyLine(string word)
	 {
		 for (int i = 0; i < word.length(); i++)
			 if (word[i] != ' ')
				 return 0;
		 return 1;
	 }
	 //判断是否是单词
	 static bool isWord(string word)
	 {
		 if (word.length() < 4)
			 return 0;
		 for (int i = 0; i < word.length(); i++)
		 {
			 if (i <= 3 && (word[i] < 'a' || word[i] > 'z'))
				 return 0;
			 if (!CountChar::numebr_letter(word[i]))
				 return 0;
		 }
		 return 1;
	 }
	 //判断是否是字母数字
	static bool numebr_letter(char c)
	 {
		 if (c >= '0' && c <= '9')
			 return 1;
		 if (c >= 'a' && c <= 'z')
			 return 1;
		 return 0;
	 }
};
#endif

