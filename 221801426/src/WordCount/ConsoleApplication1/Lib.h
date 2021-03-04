#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <regex>
#include <map>
#include <algorithm>
#include <unordered_map>
#define psi pair<string, int>
#define vpsi vector<psi>


using namespace std;

int CharCount(const char* filename);
int LinesCount(const char* filename);
int WordsCount(const char* filename);
void WordsPrint(const char* filename1, const char* filename2, int num); 

