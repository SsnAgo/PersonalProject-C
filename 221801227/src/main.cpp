#include "head.h"

int main() {
    //char buffer[500]; //�����ļ��е�һ��
    string buffer;
    fun myfun;

    int charCnt = 0,
        wordCnt = 0,
        lineCnt = 0;

    while (getline(cin, buffer)) {
        string str = buffer;
        ++lineCnt;
        //charCnt += strlen(buffer);
        charCnt += buffer.length();
        wordCnt += myfun.countWord(str);
        myfun.getWord(str);
    }
    //myfun.showWord(); //������е��ʼ�����ִ���

    // ǰ3��
    cout << "characters: " << charCnt << endl;
    cout << "words: " << wordCnt << endl;
    cout << "lines: " << lineCnt << endl;

    vector<PAIR> mymapvec(myfun.mymap.begin(), myfun.mymap.end());
    sort(mymapvec.begin(), mymapvec.end(), CmpByValue());
    int length1 = mymapvec.size();
    // ��10��
    if (length1 <= 10) {
        for (int i = 0; i != mymapvec.size(); ++i) {
            cout << mymapvec[i].first << ": " << mymapvec[i].second << endl;
        }
    }
    else {
        for (int i = 0; i < 10; ++i) {
            cout << mymapvec[i].first << ": " << mymapvec[i].second << endl;
        }
    }
    return 0;
}


