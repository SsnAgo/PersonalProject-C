#pragma once
#pragma once
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <map>
#include <regex>
using namespace std;

typedef pair<string, int> PAIR;

// ��map��valueֵ��������ת�Ƶ���vector�У�
struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
        return rhs.second < lhs.second;
    }
};

//��map�е�key��������
struct CmpByKeyLength {
    bool operator()(const string& k1, const string& k2)const {
        return k1.length() < k2.length();
    }
};

class fun {
public:
    map<string, int, CmpByKeyLength> mymap;
    string regexp = "[a-zA-Z]{4}[a-zA-Z0-9]*";

    //����һ�У�һ���ַ����У��ĵ�����
    int countWord(string str) {
        regex words_regex(regexp); // �жϵ��ʵ�������ʽ

        auto words_begin = sregex_iterator(
            str.begin(),
            str.end(),
            words_regex);
        auto words_end = sregex_iterator();

        return distance(words_begin, words_end);
    }
    // ת��ΪСд
    string myToLower(string str) {
        for (int i = 0; i < str.length(); ++i) {
            str[i] = tolower(str[i]);
        }
        return str;
    }
    //��ȡһ���еĵ��ʼ����������map��
    void getWord(string str) {
        regex words_regex(regexp); // �жϵ��ʵ�������ʽ

        auto words_begin = sregex_iterator(
            str.begin(),
            str.end(),
            words_regex);
        auto words_end = sregex_iterator();

        for (sregex_iterator k = words_begin; k != words_end; ++k) {
            smatch match = *k;
            string match_str = myToLower(match.str());//��ȡ����
            //////////////�����ʷŽ�mapͳ������/////////////////
            map<string, int>::iterator iter1;
            iter1 = mymap.find(match_str);
            if (iter1 == mymap.end()) {
                pair<string, int> value(match_str, 1);
                mymap.insert(value);
            }
            else {
                ++mymap[match_str];
            }
        }

    }

    //������ʼ�������
    void showWord() {
        map<string, int>::iterator strmap_iter2 = mymap.begin();
        for (;strmap_iter2 != mymap.end();strmap_iter2++)
        {
            cout << strmap_iter2->first << ' ' << strmap_iter2->second << endl;
        }
    }

};