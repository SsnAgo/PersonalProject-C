#pragma once


const int MAX_LEN_STR = 100;	// �����ַ�������󳤶� 

typedef struct word_info {		// �ṹ�壺���ʼ�¼ 
	char word[MAX_LEN_STR + 1];	// ���� 
	int  n_word_repeat;			// �����ظ��Ĵ��� 
}WInfo;

typedef struct words_record {	// �ṹ�壺���ʼ�¼ 
	WInfo words[501];			// ���е��� 
	int n_word_count;			// ���ʵ����� 
}WRec;

bool is_digit(char ch);			// �ж�ch�Ƿ���һ�������ַ� 
bool is_alpha(char ch);			// �ж�ch�Ƿ���һ����ĸ 
char lowercase(char ch);		// ��chת��ΪСд 
void add_word_to_(WRec& records, const char* word);			// ��word�ӵ�records�� 
void sort_WRec(WRec& records);								// ����Ƶ�ʺ��ֵ�˳������ 
void wordcount(const char* in_file, const char* out_file);	// �������ļ�in_file����ͳ�ƣ������out_file
