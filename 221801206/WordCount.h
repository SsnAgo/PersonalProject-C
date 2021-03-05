#ifndef  __WORDCOUNT_H
#define  __WORDCOUNT_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class WordCount;


class WordCount
{
	private:
		int ccount;    //�ַ���
		int wcount;    //������
		int ecount;    //����
		map<string,int> wordmap;
		
	public:
		WordCount();
		
		//��Ա���� 
		void charAndEntercount(string pathstr);    //ͳ���ַ�����ͬʱͳ������ 
		void wCount(string pathstr);				//ͳ�Ƶ�������������wordmap 
		void wordMapSort();							//��wordmap��������ֻ������Ƶ��ߵ�10�������10���ȫ������ 
};

#endif
