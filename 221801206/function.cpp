#include "WordCount.h"
#include <cmath>
#include <fstream>
#include <map>
#include <string>
#include <iostream>

void WordCount::charAndEntercount(string pathstr){
	const char*path=pathstr.data();
	
	int cc=0;
	int ec=0;	
	char temp;
	int isnewEnter=1;
	
	ifstream infs;
	infs.open(path,ifstream::in);
	
	if(!infs)
	{
		cout<<"Cannot open file";
	}
	else
	{
		//�����ȡ�ַ� 
		while(!infs.eof())
		{
			infs.get(temp);
			cc++;
			if(temp=='\n')
			{
				isnewEnter=1;
			}
			else
			{
				if((temp=='\f'||temp=='\r'||temp=='\t'||temp=='\v'||temp=='\b'||temp==' ')&&isnewEnter==1);
				else
				{
					ec+=isnewEnter;
					isnewEnter=0;
				}
			}
		}
		cc--;
		infs.close();
	}
	
	ccount=cc;
	ecount=ec;
}

void WordCount::wCount(string pathstr){
	int wcot=0;			 //��Ч���ʸ��� 
		
	map<string,int> *wdmap;
	wdmap=&wordmap;		  //��wordmap�ĵ�ַ��ֵ��wdmap�������޸�wdmapʱҲ���޸�wordmap 
	
	string temp;		 //��ȡ�ļ�ÿ������ 
	bool isefct=true;    //�ж��Ƿ�Ϊ��Ч���� 
	string word="";		 //��ʱ��ŵ��� 
	int wordlength=0;	 //word�����ж� 
	
	ifstream infs;
	infs.open(pathstr,ifstream::in);

	if(!infs);
	else
	{
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
					 
					//��Ϊ��Ч���ʣ������wdmap
					if( isefct && wordlength>=4 ) 
					{
						cout<<word<<'\n';
						wcot++;
						
						map<string,int>::iterator iter=(*wdmap).find(word);
 
						if( iter!=(*wdmap).end())
						{
							(*wdmap)[word]++;
							wcot--;
						}
						else
						{
							(*wdmap).insert(pair<string, int>(word, 1));
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
							word+=tolower(ch);
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
	}
		wcount=wcot;	
}

void wordMapSort(){
	
} 
