#include "CountFile.h"

string countFile::getString(ifstream& in){
	char ch;
	//文本内容作为字符串存储
	string str; 
	while((ch=in.get())!=EOF){
		//asii码字符范围 
		if(ch>0  &&  ch<=127){
			//字母大写->小写
			if(ch>=65  &&  ch<=90){
    		ch+=32;
			}
			str.append(1,ch);
		}
	}
	return str;
}
void countFile::countChara(string str,ofstream& out){
	out<<"character: "<< str.length()<<endl;
}
void countFile::countLine(string str,ofstream& out){
	int lines=0;
	
	string s;
    for(int i=0; i<str.length(); i++){
		if(str[i]!='\n'){
			if(str[i]!=' ' && str[i]!='\t' && str[i]!='\r') 
			s+=str[i];
		}
		else{
			if(s!=""){
				lines++;
				s="";
			}
		}
	}
	//文件最后无‘\n’情况 
		if(s!=""){
			lines++;
			s="";
		}
	out<<"lines: "<<lines<<endl;
}

void countFile::loadMap(string str){
    
	for(int i=0;i<str.length()-3;i++){
		//跳过非字母和非数字字符
		while(i<str.length() && !isdigit(str[i]) && !islower(str[i])){ 
			i++;
		} 
		
    	string temp;//存储合理单词 
		bool flag=true;	//判断是否符合四个字母开头 
		
		for(int j=0;j<4;j++){
			if(!islower(str[i+j])){
				flag=false;
				break;
			}
		}
		if(flag){
			for(int j=0;j<4;j++){
				temp.append(1,str[i+j]);
			}
			i+=4;
			while(i<str.length() && isdigit(str[i]) || islower(str[i])){
				temp.append(1,str[i]);
				i++; 
			} 
			mp[temp]++;
		}
	}
}

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first != b.first)return a.first > b.first;
	return a.second < b.second;
}

vector<pair<int,string> > countFile::getSort()
{
	map<string, int>::iterator it;
	vector<pair<int, string> > ve;
	for (it=mp.begin(); it!=mp.end(); it++)
	{
		ve.push_back(make_pair(it->second,it->first));
	}
	sort(ve.begin(), ve.end(),cmp);
	
	return ve;
}

void countFile::countWord(ofstream& out){
	int word=0;
	map<string, int>::iterator it;
	for (it=mp.begin(); it!=mp.end(); it++)
	{
		word+=it->second;
	}
	out<<"words: "<<word<<endl;
}
