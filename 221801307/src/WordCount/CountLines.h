#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#define EMPTY 0    //空行为0
#define NOTEMPTY 1 //非空为1

/*
函数名:CountLines
描述:计算文件的行数，跳过空行。
参数:@filename:需要统计的文件
返回:@int:总行数
*/

int CountLines(char * filename);