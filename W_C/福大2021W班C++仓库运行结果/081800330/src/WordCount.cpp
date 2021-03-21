#include<iostream>
#include"TxtInput.h"
#include"TxtOutput.h"
#include"AppData.h"
#include<time.h>
#include"CountChar.h"
#include"TxtOutput.h"
using namespace std;
int main(int argc, char* argv[])
{
	clock_t start, end;  
	start = clock();
	string filename = argv[1];
	string filename2 = argv[2];
	TxtInput *input = new TxtInput(filename);
	TxtOutput* output = new TxtOutput(filename2);
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

	cout << "�ַ�����" << data->number_asc << endl;
	cout << "��������:" << data->number_words << endl;
	cout << "���� :" << data->number_line << endl;
	output->OutTxt(data);
	end = clock();   
	cout << "���뾭����ʱ����" << (end - start)*1.0 / CLK_TCK*1.0 << endl;
}
