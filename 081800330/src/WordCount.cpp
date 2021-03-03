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
		if (s == '\n' || s == '\r' || s == ' ' || s == '\t')
		{

		}
		if (flag)
		{
			switch (s)
			{
			case 'n': {
				data->number_asc++;
				CountChar::countChar(temp, data);
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
		else
		{
			temp += s;
		}
		cout << s ;
	}
	end = clock();   
	cout << "代码经过的时间是" << (end - start)*1.0 / CLK_TCK*1.0 << endl;
}
