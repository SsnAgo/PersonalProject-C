#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#define EMPTY 0    //����Ϊ0
#define NOTEMPTY 1 //�ǿ�Ϊ1

/*
������:CountLines
����:�����ļ����������������С�
����:@filename:��Ҫͳ�Ƶ��ļ�
����:@int:������
*/

int CountLines(char *filename);