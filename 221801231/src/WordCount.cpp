/************************************************************
 FileName: WordCount.cpp
 Author:Zou Pufan Version:7.0 Date:2021/2/27
 Description: // ģ������
 Version: // �汾��Ϣ
 Function List: // ��Ҫ�������书��
 1. -------
 History: // ��ʷ�޸ļ�¼
 <author> <time> <version > <desc>
 David 96/10/12 1.0 build this moudle
***********************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX_NUM 1024

using namespace std;
class word
{
public:
	word()
	{
		this->occurCount = 0;
		this->wordName = "";
	}
	word(string wordN)
	{
		this->wordName = wordN;
		this->occurCount=1;
	}


	int occurCount;
	string wordName;
};
class myfile
{
public:
	myfile()
	{
		this->fileName = "";
		this->characterNum = this->wordNum = 0;
	}
	myfile(string s)
	{
		this->fileName = s;
		this->characterNum = this->wordNum = 0;
	}
	int Countchar(fstream& in,string outputFileName);
	int Countword(fstream& in, string outputFileName);
	int Countline(fstream& in, string outputFileName);
	/*bool sortWordTimes(const word&a, const word &b);*/
	void Countwordoccurtimes(fstream& in,string outputFileName);
	
private:
	string fileName;
	int characterNum;
	int wordNum;
	vector<word> wVector;
};
