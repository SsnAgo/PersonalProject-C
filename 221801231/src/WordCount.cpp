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
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <direct.h>
#define MAX_NUM 1024
using namespace std;
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
	void Sortmap();
	
private:
	string fileName;
	int characterNum;
	int wordNum;
	map<word, int> wMap;
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
	char tempCh;
	in.unsetf(ios_base::skipws);//���ò��������з��Ϳհ׷�
    in>>tempCh;
    while(!in.eof())
    {
    	totalCount++;
   	    in>>tempCh;
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
/*************************************************
 Description:ͨ����������ļ����������ַ��Ķ�ȡ������ȡ�����ַ�ƴ��Ϊ�ַ������������ָ������ǰƴ�ӳɵ��ַ������м�飬�ж��Ƿ�Ϊ��Ч�ĵ��ʣ�����Ч�����vector�����С���Ч��������
 Input: ��������ֱ�Ϊfstream�������in�������ļ��Ķ�ȡ����string��outputFilename����д������ļ����ļ���// �������˵��������ÿ����������
 // �á�ȡֵ˵�����������ϵ��
 Output: ���ֵΪ�����output�ļ��ĵ����ܼƳ��ִ���// �����������˵����
 Return:��returnֵ // ��������ֵ��˵��
 Others: // ����˵��
*************************************************/
int myfile::Countword(fstream &in, string outputFileName)
{
	bool isWord = true;//�ж��ַ��������Ƿ���ϵ������
	fstream out;
	out.open(outputFileName.c_str(),ios::app);

	if (!in.is_open())
	{
		cout << "�޷����ļ�" << endl;
		exit(0);
	}
	int totalCount = 0;
	string wordString = "";
	char temp;
    if(in.eof())
    {
   	cout<<"�ļ�����ĩβ"<<endl;
    }
    in.unsetf(ios_base::skipws);//���ò��������з��Ϳհ׷�
    while(!in.eof())
    {

   	in>>temp;
	if (temp <= 'Z'&&temp >= 'A')//����ַ�Ϊ��д��ĸ����ת��ΪСд��ĸ
	{
		temp += 32;
	}
	if (temp <= 32 || temp>126||temp=='\n')//�ж��Ƿ������ָ��������ִ����������
	{
		if (wordString.length() < 4)//������ʳ���С��4����ֱ������������ַ�������
		{
			wordString = "";
			continue;
		}
		for (int i = 0;i < 4;i++)
		{
			if (!isalpha(wordString[i]))//�ж��ַ���ǰ��λ�Ƿ�Ϊ��ĸ����Ϊ��ĸ��ֱ�ӽ���ѭ��
			{
				wordString = "";
				isWord = false;
				break;
			}

		}
		if (!isWord)//�����Ϊ���������ִ����һ��whileѭ������ִ�����´���
		{
			isWord = true;
			continue;
		}
		totalCount++;

		//ͨ��find_if��������Զ����findword�����жϵ����Ƿ���vector�����г��ֹ��������ֹ�����ӵ��ʴ������ɣ�δ���ֹ�������µ�Ԫ�ء�
		vector<word>::iterator it = find_if(this->wVector.begin(), this->wVector.end(), findword(wordString));
		if (it != this->wVector.end())
		{
			it->occurCount++;
		}
		else
		{
			this->wVector.push_back(word(wordString));
			
		}
		wordString = "";
	}
	else	wordString=wordString+temp;
    }
    if (!wordString.empty())//���ļ���ȡ������û�������ָ���ȴ�ַ�����ȴ�������ݣ�Ҫ�������һ�μ�顣
    {
	   if (wordString.length() < 4)
	   {
		   wordString = "";
		  
	   }
	   for (int i = 0;i <= 4;i++)
	   {
		   if (!isalpha(wordString[i]))
		   {
			   wordString = "";
			   isWord = false;
			   break;
		   }

	   }
	   if (isWord)
	   {
		   for (int j = 0;j < wordString.length();j++)
		   {

			   if (wordString[j] <= 'Z'&&wordString[j] >= 'A')
			   {
				   wordString[j] += 32;
			   }
		   }
		   totalCount++;
		   vector<word>::iterator it = find_if(this->wVector.begin(), this->wVector.end(), findword(wordString));
		   if (it != this->wVector.end())
		   {
			   it->occurCount++;

		   }
		   else
		   {
			   this->wVector.push_back(word(wordString));

		   }
		   wordString = "";
	   }
	   else
	   {
		   isWord = true;
	   }
    }
    in.close(); 
    in.clear();
    out << "word:" << totalCount << endl;//������ʵ�����
    out.close();
    out.clear();
 	return totalCount;
}
