#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Lib {
public:
    typedef struct {
        string word;
        int num;

    }words;

    vector<words> v;
    void wordsort() {
        for (int i = 0; i < v.size() - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[i].num < v[j].num) {
                    words temp;

                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
                else if (v[i].num == v[j].num) {
                    if (v[i].word.compare(v[j].word) > 0) {
                        words temp;

                        temp = v[i];
                        v[i] = v[j];
                        v[j] = temp;
                    }
                }
            }
        }
    }

    int CountLetter(char* inter) {
        ifstream fin(inter);
        
        if (!fin) {
            return 0;
         }
        

        char c;
        //字符数
        int count = 0;

        while(fin.get(c)){
            count ++;
		}
        fin.close();
        return count;
    }

    int CountWord(char* inter) {
        ifstream fin(inter);
        try {
            if (!fin) {
                throw inter;
            }
        }
        catch (char* s) {
            cout << "open file:[" << s << "] failed" << endl;
            exit(1);
        }

        string s;
        string aword = "";
        int word = 0;
        //是否是单词第一个字母 
        int isfirst = 1;
        //单词开头字母数 
        int letters = 0;

        while (getline(fin, s)) {
            for (int i = 0; i < s.size(); i++) {
                if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] <= '9' && s[i] >= '0')) {
                    if (isfirst == 1) {
                        isfirst = 0;
                        while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                            if (isupper(s[i])) {
                                s[i] = tolower(s[i]);
                            }
                            aword.append(1, s[i]);
                            letters++;
                            i++;
                        }
                        while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] <= '9' && s[i] >= '0')) {
                            if (isupper(s[i])) {
                                s[i] = tolower(s[i]);
                            }
                            aword.append(1, s[i]);
                            i++;
                        }
                        if (letters >= 4) {
                            word++;
                            int ishave = 0;
                            for (int j = 0; j < v.size(); j++) {
                                if (v[j].word == aword) {
                                    ishave = 1;
                                    v[j].num++;
                                }
                            }
                            if (ishave == 0) {
                                words newword;
                                newword.word = aword;
                                newword.num = 1;
                                v.push_back(newword);
                            }
                        }
                        isfirst = 1;
                        letters = 0;
                        aword = "";
                    }
                }
            }
        }
        fin.close();
        return word;
    }

    int CountRow(char* inter) {
        ifstream fin(inter);
        try {
            if (!fin) {
                throw inter;
            }
        }
        catch (char* s) {
            cout << "open file:[" << s << "] failed" << endl;
            exit(1);
        }
        int rows = 0;
        int isnull = 1;
        string s;

        while (getline(fin, s)) {
            for (int i = 0; i < s.size(); i++) {
                if ((s[i] != ' ') && (s[i] != '\t') && (s[i] != '\r') && (s[i] != '\n') && (s[i] != '\v') && (s[i] != '\f')) {
                    isnull = 0;
                    break;
                }
            }
            if (isnull == 0) {
                rows++;
                isnull = 1;
            }
        }
        fin.close();
        return rows;
    }
    int a() {
        return 0;
    }


};
