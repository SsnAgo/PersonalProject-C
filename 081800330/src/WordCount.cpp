#include<iostream>
#include"TxtInput.h"
#include"TxtOutput.h"
#include"AppData.h"
#include<time.h>
#include"CountChar.h"

using namespace std;
int main(int argc, char* argv[])
{
	clock_t start, end;  
	start = clock();
	string filename = argv[1];
	TxtInput *input = new TxtInput(filename);
	cin.unsetf(ios::skipws);
	int count = 0;
	AppData *data = new AppData();
	string temp = "";
	bool flag = false;
	while (!input->in.eof())
	{
		char  s;
		s = input->in.get();
		if (flag)
		{
			switch (s)
			{
			case 'n': {
				data->number_asc++;
				data->number_line++;
				CountChar::countChar(temp, data);
				temp = "";
				break;
			}
			case 'r': {
				temp += ' ';
				break;
			}
			case 't': {
				temp += ' ';
				break;
			}
			default: {
				temp += ' ';
				break;
			}
			}
			flag = 0;
		}
		else if (s == '\n' && temp.length())
		{
			CountChar::countChar(temp,data);
			data->number_line++;
			temp = "";
		}
		else if (s == '\\')
		{
			flag = 1;
		}
		else if (s == '\r')
		{
			temp += ' ';
		}
		else if (s == '\t')
		{
			temp += ' ';
		}
		else if(s!= '\n')
		{
			temp += s;
		}
		
	}
	cout << "字符总数" << data->number_asc << endl;
	cout << "单词总数:" << data->number_words << endl;
	cout << "行数 :" << data->number_line << endl;
	end = clock();   
	cout << "代码经过的时间是" << (end - start)*1.0 / CLK_TCK*1.0 << endl;
}
