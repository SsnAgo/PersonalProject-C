#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <ctype.h>
#include <map> 
#include <algorithm>
#include <functional>
#include "WordCount.h"

using namespace std;

int main(int argc, char *argv[]){
	string pathStr;
	cin>>pathStr;

	const char*path=pathStr.data();
	
	map<string,int> *wordmap;
	map<string,int> map2;
	wordmap=&map2;
	int wcot=0;			 //��Ч���ʸ��� 
		
	string temp;		 //��ȡ�ļ�ÿ������ 
	bool isefct=true;    //�ж��Ƿ�Ϊ��Ч���� 
	string word="";		 //��ʱ��ŵ��� 
	int wordlength=0;	 //word�����ж� 
	
	ifstream infs;
	infs.open(path,ifstream::in);

	if(!infs)
	{
		cout<<"Cannot open file.\n";
		return 0;
	}
	else
	{
		cout<<"open"<<'\n';
		while(getline(infs,temp))
		{
			int l=temp.length();
			for(int i=0;i<l;i++)
			{
				char ch=temp[i];
				ch=tolower(ch);
				//�����ָ����򵽴����ĩβ 
				if(ch==' '||!isalnum(ch)||i==l-1)    
				{
					//��ĩ�ַ����ж� 
					if(i==l-1&&isalnum(ch))		
					{
						if( isdigit(ch)!=0 && wordlength<4 )
						{
							isefct=false;
						}
						else
						{
							word+=ch;
							wordlength++;
						}
					}
					 
					//��Ϊ��Ч���ʣ������map
					if( isefct && wordlength>=4 ) 
					{
						wcot++;
						
						map<string,int>::iterator iter=(*wordmap).find(word);
 
						if( iter!=(*wordmap).end())
						{
							(*wordmap)[word]++;
							wcot--;
						}
						else
						{
							(*wordmap).insert(pair<string, int>(word, 1));
						}

					}
					
					wordlength=0;
					word="";
					isefct=true;
				}
				else
				{
					if(isefct)
					{
						if( isdigit(ch)!=0 && wordlength<4 )		
						{
							isefct=false; 	//�ڵ���ǰ4λ�г������֣�Ϊ��Ч����
							wordlength=0;
							word="";
						}
						else
						{
							word+=ch;
							wordlength++;
						}
					}
				}
			}
			
			wordlength=0;
			word="";
			isefct=true;
		}
		infs.close();
		cout<<wcot<<'\n';	

	}

	return 0;
}
