#pragma once
#ifndef LIB_H
#define LIB_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#define MIN_WORD_SIZE 4
using namespace std;
class wordCount
{
public:
	wordCount(string inFileName, string outFileName);
	~wordCount();
	void handleInPut();
	void outPutAll();
	void outPutCharacterCount();
	void outPutWordCount();
	void outPutFrequencyCount();

	int handleCharacter(char c);//处理输入的每一个字符，用于 1.统计字符数量
	void wordBreak();//当出现字母数字字符时进行单词的分割和判断
	int newWord(string key, int value);//记录新的单词，用于 2.统计单词数量
	bool isRepeatWord();//记录重复出现的单词词频，用于 3.统计最多的10个单词及其词频

private:
	char singleCharacter;
	string singleWord = "";
	map<string, int> wordList;
	int characterCnt = 0;
	int wordCnt = 0;
	int cnt = 0;
	ifstream infile;
	ofstream outfile;
};

#endif
