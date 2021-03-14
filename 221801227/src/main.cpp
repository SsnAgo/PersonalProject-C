#include "head.h"

int main() {
    //char buffer[500]; //读出文件中的一行
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
    //myfun.showWord(); //输出所有单词及其出现次数

    // 前3行
    cout << "characters: " << charCnt << endl;
    cout << "words: " << wordCnt << endl;
    cout << "lines: " << lineCnt << endl;

    vector<PAIR> mymapvec(myfun.mymap.begin(), myfun.mymap.end());
    sort(mymapvec.begin(), mymapvec.end(), CmpByValue());
    int length1 = mymapvec.size();
    // 后10行
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


