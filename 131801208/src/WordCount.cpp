#include <string>
#include <fstream>
#include <string.h>
#include <map>
#include <algorithm>
#include <iostream>
#include<ctime> 
 
using namespace std;
int word_count=0;//����ͳ�Ƶ����� 
multimap<int, string, greater<int> > mapB;//����map��������һ��mapʹ�����Ƶ������ 
map<string, int> mapA; //��һ���浥��,�ڶ����浥�ʳ��ֵĴ���;


bool isnum_str(char str)  //�ж��Ƿ����ַ�������
{
	if((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9') )
		return true;
	else
		return false;
}
bool is_lower_alpha(char str){
	if(str >= 'a' && str <= 'z')
		return true;
    else
		return false;
}

void count(ifstream &outfile, int *cnt )  //ͳ�ƺ���
{ 
	char str[256];
	//int wrong=0;
	while(outfile.getline(str,256))
	{ 
		/*wrong++;
		if(wrong>256){
			cout<<"wrong line num";
			break;
		}*/
    	int tmp = 0;
    	for(int i = 0; i < strlen(str); i++)
		{
	  		if(str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!'){
	  				cnt[1]++;	 //ͳ�Ƶ�����	
			  }
	  
	  		if(isnum_str(str[i]))
	  		{ 
				cnt[0]++;
			    tmp++;     //ͳ���ַ�����tmp�ֲ��������������ǲ���һ�����С�
			}    
		}
	
		if(tmp != 0){
			cnt[2]++;	//ͳ������
		}                
		tmp = 0;
  }    
	return ;
}

int fcharCount(fstream &infile){	//ͳ���ַ��� 
	int a=0;//����ͳ�� �ַ��� 
	infile >> skipws;
	while(!infile.eof())
	{
		char ch;
		infile.get( ch ); 
		a++;
	}
	a-=1;//��Ϊ������һ�� \0��β ���ڱ���Ҫ���� 
	return a;
}

void countWord(ifstream &input){
	string eachline;
		
	while (getline(input, eachline))
	{
		transform(eachline.begin(),eachline.end(),eachline.begin(),::tolower);
		string::size_type start = 0;
		string::size_type end = eachline.find_first_of(".,?! ");
		int flag=0; 
		while (end != string::npos) //npos������һ�е�ͷ����
		{
			string content = eachline.substr(start, end - start);
			map<string, int>::iterator it = mapA.find(content);
			if(content.length()>3&&is_lower_alpha(content[0])&&is_lower_alpha(content[1])
			&&is_lower_alpha(content[2])&&is_lower_alpha(content[3]))//�ж��Ƿ�ǰ�ĸ������ַ� 
			{				
				if (it == mapA.end())
				{
					mapA.insert(pair<string, int>(content, 1));//��ֵ��ʱ��ֻ����pair���ͣ�
				} else
				{
					++it->second;
				}
			}			
			start = end + 1;
			end = eachline.find_first_of(".,?! ", start);			
		}
		string content = eachline.substr(start, end - start);
			map<string, int>::iterator it = mapA.find(content);
			if(content.length()>3&&is_lower_alpha(content[0])&&is_lower_alpha(content[1])
			&&is_lower_alpha(content[2])&&is_lower_alpha(content[3]))
			{				
				if (it == mapA.end())
				{
					mapA.insert(pair<string, int>(content, 1));//��ֵ��ʱ��ֻ����pair���ͣ�
				} else
				{
					++it->second;
				}
			}							
	}
 	word_count=0;
	for (map<string, int>::iterator it1 = mapA.begin(); it1 != mapA.end();++it1)
	{
		mapB.insert(pair<int, string>(it1->second, it1->first));//����map�Զ����ݳ��ִ������� 
		word_count+=it1->second;//˳��ͳ�� 
	}
}

void output(ofstream &foutput,int a,int *cnt){
	if((word_count>0||a>0)&&cnt[2]==0){
		foutput<<"��������̫�࣬�׳��쳣";
		return; 
	}
	foutput<<"�ַ���Ϊ��"<< a<<endl; 
	foutput<<"������Ϊ��"<<word_count<<endl;
	foutput<<"����Ϊ��"<< cnt[2]<<endl;
	int temp=0;
	for (map<int, string>::iterator it2 = mapB.begin(); it2 != mapB.end()&&temp<10;++it2)
	{
//		if ((it2->first) > 1)
			temp++;
			foutput << it2->second << "���ʳ��ֵĴ�����" << it2->first << endl;
		
	}
}

void test(ofstream &t){//���Ժ��� 
	for(int a=0;a<10000000;a++){
    	t<<"ddaa ";
    	if(a%50==0&&a!=0){//ÿ���ַ��� 
    		t<<"\n";
		}
	}
}

int main()
//int main(int argc,char* argv[])
{
	
    int cnt[3] = {0};
    
    ofstream t;
    t.open("input.txt");
    test(t);	
	t.close();
    clock_t start1,end1,start2,end2,start3,end3,start,end;
    
    start=clock();
	ifstream fword,fchar;//���ֹ����������� 
	ofstream foutput;
	
	foutput.open("output.txt");
	
	start1=clock();
	fchar.open("input.txt");
	count(fchar,cnt);
	fchar.close();
	end1=clock();
	
	start2=clock();
	fword.open("input.txt");
	countWord(fword);
	fword.close();
	end2=clock();
	//foutput.open(argv[2]);
	//fchar.open(argv[1]);
	//fword.open(argv[1]);
	
	//fstream infile(argv[1],ios::in);
	start3=clock();
	fstream infile("input.txt",ios::in)	;	
	int fchar_count=fcharCount(infile);
	end3=clock();
	
	output(foutput,fchar_count,cnt);
	end=clock();
	cout<<"�ܺ�ʱ"<<(double)((end-start)/1000)<<"s"<<endl;
	cout<<"ͳ���ַ���ʱ"<<(double)((end1-start1)/1000)<<"s"<<endl;
	cout<<"ͳ�Ƶ���ʱ"<<(double)((end2-start2)/1000)<<"s"<<endl;
	cout<<"ͳ��������ʱ"<<(double)((end3-start3)/1000)<<"s"<<endl;
	
			
	cout<<"�ַ���Ϊ��"<< fchar_count<<endl; 
	cout<<"������Ϊ��"<<word_count<<endl;
	cout<<"����Ϊ��"<< cnt[2]<<endl;
	

	for (map<int, string>::iterator it2 = mapB.begin(); it2 != mapB.end();++it2)
	{
//		if ((it2->first) > 1)
			cout << it2->second << "���ʳ��ֵĴ�����" << it2->first << endl;
		
	}
	
 	foutput.close();
 	fword.close();
 	
 	
 	
	int a;
	cin >> a;
 	 
}

