#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#define Separator(x) (isspace(x) || (!IsNum(x) && !isalpha(x))) 
#define IsNum(x) (x >= '0' && x <= '9')

#define OUTWORD 0
#define P1 1
#define P2 2
#define P3 3
#define NotAWord 4 
#define VALIDWORD 5
#define ERROR 6

/*
函数名:Transition
描述: 状态转换过程并添加单词的计数器。
参数 :@state当前状态
	  @input:当前输入
	  @count:单词的计数器
返回:@int:state新状态
*/
int Transition(int state, char input, int *count);

/*
函数名:CountWords
描述:计算单词总数。单词的开头是四个连续的单词字母，后面跟着字母和数字
参数:@filename:需要统计的文件
返回:@int:单词总数
*/
int CountWords(char *filename);