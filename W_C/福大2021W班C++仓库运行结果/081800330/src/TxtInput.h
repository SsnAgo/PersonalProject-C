#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class TxtInput
{
public:
	 ifstream in;
	TxtInput(string filename)
	{
		in.open(filename, ios::in);
		if (!in.is_open())
		{
			cout << "���ļ�ʧ�ܣ�" << endl;
		}
	}
};

