#pragma once
#include<iostream>
#include<queue>
#include<unordered_map>
#include<fstream>
#include<string>

using namespace std;

#define Separator(x) (isspace(x) || (!IsNum(x) && !isalpha(x))) 
#define IsNum(x) (x >= '0' && x <= '9')

#define OUTWORD 0 // ��ǰû��ʶ�𵽺Ϸ�����
#define A 1
#define B 2
#define C 3
#define NoWord 4 
#define WORD 5 //��ǰʶ���˺Ϸ�����
#define ERROR 6
#define WORDCOUNT 20

/*
������:MySort
���� :ǰ10���������������򷽷���
*/
bool MySort(const pair<int, string>&word1, const pair<int, string>&word2);


/*
������:TransWord
����:״̬ת�Ʋ�����ȷ�ĵ�����ȡ���ַ�����
����:@state��ǰ״̬
	 @input:��ǰ����
	 @word:��һ���Ϸ��ĵ��ʱ���⵽�������洢�����
����:@int:��״̬
*/
int TransWord(int state, char input, string &word);

/*
������:IntoHashTable
����:�ڹ�ϣ���в���Ϸ��ĵ��ʡ�������TransWord()����
����:@word:�Ϸ��ĵ���
����:void
*/
void IntoHashTable(string &word);

/*
������:WordNums
����:����ÿ���������ļ��г��ֵĴ������洢��һ����ϣ�����������ת����IntoHashTable�İ�װ��
����:@filename:��Ҫͳ�Ƶ��ʵ��ļ�
����:void
*/
void WordNums(char *filename);

/*
��������:TopWords
����:��ʾƵ����ߵ�10�����ʡ�
����:
����:vector<pair<int, string>>:ǰ10�����ʼ�����������б�
*/
vector<pair<int, string>> TopWords();

/*
������:OutputToFile
���� :��ǰ10�������������Ϊ��output.txt�����ļ���
���� :@topwords:top10�����б�
����:int:��������ȷ��Ϊ0������Ϊ - 1��
*/
int OutputF(vector<pair<int, string>> & Topwords,char *filename);

/*
������:OutputB
����:���ǰ10�����ʵ���׼���
����:@topwords : top10�����б�
����:int:��������ȷ��Ϊ0������Ϊ - 1��
*/
int OutputB(vector<pair<int, string>> & Topwords);