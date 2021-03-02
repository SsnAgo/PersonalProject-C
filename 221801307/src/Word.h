#pragma once
#include<iostream>
#include<queue>
#include<unordered_map>
#include<fstream>
#include<string>

using namespace std;

#define Separator(x) (isspace(x) || (!IsNum(x) && !isalpha(x))) 
#define IsNum(x) (x >= '0' && x <= '9')

#define OUTWORD 0 // 当前没有识别到合法单词
#define A 1
#define B 2
#define C 3
#define NoWord 4 
#define WORD 5 //当前识别到了合法单词
#define ERROR 6
#define WORDCOUNT 20

/*
函数名:MySort
描述 :前10个单词向量的排序方法。
*/
bool MySort(const pair<int, string>&word1, const pair<int, string>&word2);


/*
函数名:TransWord
描述:状态转移并将正确的单词提取到字符串中
参数:@state当前状态
	 @input:当前输入
	 @word:当一个合法的单词被检测到，它被存储在这里。
返回:@int:新状态
*/
int TransWord(int state, char input, string &word);

/*
函数名:IntoHashTable
描述:在哈希表中插入合法的单词。被引入TransWord()函数
参数:@word:合法的单词
返回:void
*/
void IntoHashTable(string &word);

/*
函数名:WordNums
描述:计算每个单词在文件中出现的次数，存储到一个哈希表。这个函数是转换和IntoHashTable的包装器
参数:@filename:需要统计单词的文件
返回:void
*/
void WordNums(char *filename);

/*
函数名称:TopWords
描述:显示频率最高的10个单词。
参数:
返回:vector<pair<int, string>>:前10个单词及其计数器的列表。
*/
vector<pair<int, string>> TopWords();

/*
函数名:OutputToFile
描述 :将前10个单词输出到名为“output.txt”的文件中
参数 :@topwords:top10单词列表
返回:int:如果输出正确则为0，否则为 - 1。
*/
int OutputF(vector<pair<int, string>> & Topwords,char *filename);

/*
函数名:OutputB
描述:输出前10个单词到标准输出
参数:@topwords : top10单词列表
返回:int:如果输出正确则为0，否则为 - 1。
*/
int OutputB(vector<pair<int, string>> & Topwords);