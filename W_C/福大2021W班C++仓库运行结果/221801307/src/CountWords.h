#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#define Separator(x) (isspace(x) || (!IsNum(x) && !isalpha(x))) 
#define IsNum(x) (x >= '0' && x <= '9')

#define OUTWORD 0
#define A 1
#define B 2
#define C 3
#define NoWord 4 
#define WORD 5
#define ERROR 6

/*
������:Transition
����: ״̬ת�����̲���ӵ��ʵļ�������
���� :@state��ǰ״̬
	  @input:��ǰ����
	  @count:���ʵļ�����
����:@int:state��״̬
*/
int Transition(int state, char input, int *count);

/*
������:CountWords
����:���㵥�����������ʵĿ�ͷ���ĸ������ĵ�����ĸ�����������ĸ������
����:@filename:��Ҫͳ�Ƶ��ļ�
����:@int:��������
*/
int CountWords(char *filename);