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
/*************************************************
 Description:ͨ����������ļ����������ַ��Ķ�ȡ�Լ����ַ�����
 Input: ��������ֱ�Ϊfstream�������in�������ļ��Ķ�ȡ����string��outputFilename����д������ļ����ļ���// �������˵��������ÿ����������
 // �á�ȡֵ˵�����������ϵ��
 Output: ���ֵΪ�����output�ļ����ַ����ִ���// �����������˵����
 Return:��returnֵ // ��������ֵ��˵��
 Others: // ����˵��
*************************************************/
int myfile::Countchar(fstream &in, string outputFileName)
{
	fstream out;
	out.open(outputFileName.c_str(),ios::app);
	int totalCount=0;
	char temp;
   in>>noskipws;//���ò��������з��Ϳհ׷�
   in>>temp;
   while(!in.eof())
   {
   	totalCount++;
   	in>>temp;
   }
   out<<"characters:"<<totalCount<<'\n';
   out.close();
   out.clear();
	return totalCount;
}
/*************************************************
 Description:ͨ����������ļ����������еĶ�ȡ��ͳ���ļ�������
 Input: ��������ֱ�Ϊfstream�������in�������ļ��Ķ�ȡ����string��outputFilename����д������ļ����ļ���// �������˵��������ÿ����������
 // �á�ȡֵ˵�����������ϵ��
 Output: ���ֵΪ�����output�ļ���input�ļ����ܹ���������// �����������˵����
 Return:��returnֵ // ��������ֵ��˵��
 Others: // ����˵��
*************************************************/
int myfile::Countline(fstream &in, string outputFileName)
{
	fstream out;
	out.open(outputFileName.c_str(),ios::app);
	if (!in.is_open())
	{
		cout << "�޷����ļ�" << endl;
		exit(0);
	}
	int totalCount = 0;
	string line;
	while (!in.eof())
	{
		getline(in,line);
		for (int i = 0;i < line.length();i++)
		{
			if (!isspace(line[i]))//���ļ��������еĶ�ȡ���ж��Ƿ���ڷǿհ��ַ���
			{
				totalCount++;
				break;
			}
		}
	}
	out << "line:" << totalCount << endl;
	out.close();
	out.clear();
	return totalCount;
}
