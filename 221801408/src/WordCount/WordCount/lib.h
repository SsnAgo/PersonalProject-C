#pragma once
#include <iostream>
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>
#include<string.h>
#include<sstream>
#include<fstream>
#include<string>
#include<iterator>
#include<cctype>
#include<ctype.h>
#include<unordered_map>
#include<algorithm>

using namespace std;
class WordCount
{

private:
	FILE * f;
	const char *input_file;
	const char *output_file;
public:
	WordCount(FILE *a, const char *b, const char*c)
	{
		f = a;
		input_file = b;
		output_file = c;
	}
	~WordCount() {};

};