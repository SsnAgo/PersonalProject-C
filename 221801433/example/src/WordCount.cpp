#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Lib.h"
using namespace std;

int main(int argc, char* argv[]) {
	Lib lib;
    int count = lib.CountLetter(argv[1]);
    int word = lib.CountWord(argv[1]);
    int rows = lib.CountRow(argv[1]);
    ofstream out(argv[2]);
    try{
        if(!out){
            throw argv[2];
        }
    }
    catch (char* s){
        cout<<"open file:["<<argv[2]<<"] failed"<<endl;
        exit(1);
    }
    
    out << "characters: " << count << '\n';
    out << "words: " << word << '\n';
    out << "lines: " << rows << '\n';
    lib.wordsort();
    for(int i = 0;(i < lib.v.size() && i < 10);i ++){
        out << lib.v[i].word << ": " << lib.v[i].num << '\n';
    }
}

