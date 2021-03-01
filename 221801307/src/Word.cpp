#include "Word.h"

unordered_map<string, int> table;
unordered_map<string, int>::iterator iter;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> wordQueue;

bool MySort(const pair<int, string>& word1, const pair<int, string>& word2){
	if (word1.first == word2.first){   //如果单词有相同的频率，则按字典顺序输出
		return word1.second < word2.second;
	}
	else{   //按频率排序，从高到低
		return word1.first > word2.first;
	}
}

int TransWord(int state, char input, string &word){
	switch (state){
	case OUTWORD:
		if (Separator(input)) return OUTWORD;
		if (isalpha(input)) { word += input; return P1; }
		if (IsNum(input)) return NotAWord;

	case NotAWord:
		if (Separator(input)) return OUTWORD;
		else return NotAWord;

	case P1:
		if (IsNum(input)) { word.clear(); return NotAWord; }
		if (isalpha(input)) { word += input; return  P2; }
		else { word.clear(); return OUTWORD; }

	case P2:
		if (IsNum(input)) { word.clear(); return NotAWord; }
		if (isalpha(input)) { word += input; return  P3; }
		else { word.clear(); return OUTWORD; }

	case P3:
		if (IsNum(input)) { word.clear(); return NotAWord; }
		if (isalpha(input)) { word += input; return VALIDWORD; }
		else { word.clear(); return OUTWORD; }

	case VALIDWORD:
		if (isalnum(input)) { word += input; return VALIDWORD; }
		else{
			IntoHashTable(word);
			//cout << word << endl;
			word.clear();
			return OUTWORD;
		}
	}
	return ERROR;
}

void IntoHashTable(string & word){
	if (( iter = table.find(word)) == table.end()){ // 存入新的单词
		pair<string, int> newWord = pair<string, int>(word, 1);
		table.insert(newWord);
	}
	else{ //以前出现过的一个词
		iter->second++;
		pair<string, int> oldword = pair<string, int>(word, iter->second);
	}
}

void WordNums(char *filename){
	string word;
	char c;
	fstream file;
	file.open(filename, ios::in);
	int state = OUTWORD;
	while (file.get(c) && state != ERROR){
		c = tolower(c);
		state = TransWord(state, c, word);
	}
	if (state == VALIDWORD){
		IntoHashTable(word);
	}
}

vector<pair<int, string>> TopWords(){
	for (iter = table.begin(); iter != table.end(); iter++) {
		pair<int, string> currentWord = make_pair(iter->second, iter->first);
		if (wordQueue.size() == WORDCOUNT) {
			pair<int, string> minFreqWord = wordQueue.top();
			if ((currentWord.first == minFreqWord.first && currentWord.second < minFreqWord.second) || (currentWord.first > minFreqWord.first)) {
				wordQueue.pop();
				wordQueue.push(currentWord);
			}
		}
		else {
			wordQueue.push(currentWord);
		}
	}

	vector<pair<int, string>> Top10words;
	while (!wordQueue.empty()) {
		Top10words.push_back(wordQueue.top());
		wordQueue.pop();
	}

	sort(Top10words.begin(), Top10words.end(), MySort);
	table.clear();
	return Top10words;
}

int OutputF(vector<pair<int, string>> &Topwords, char *filename)
{
	if (Topwords.size() == 0){
		return -1;
	}

	fstream file;
	file.open(filename, ios::app);
	if (!file) {
		printf("Failed to create output file.\n");
		return -1;
	}
	int size = Topwords.size();
	for (int i = 0; i < size && i < 10; i++) {
		const char *word = (Topwords[i]).second.c_str();
		file << "<";
		file << word;
		file << ">: ";
		file << (Topwords[i]).first;
		file << endl;
	}
	printf("Top 10 words have been stored in output.txt\n");
	return 0;
}

int OutputB(vector<pair<int, string>>& Topwords)
{
	if (Topwords.size() == 0) {
		return -1;
	}

	vector<pair<int, string>>::iterator iter;
	for (iter = Topwords.begin(); iter != Topwords.end(); iter++) {
		const char *word = iter->second.c_str();
		printf("%s: %d\n", word, iter->first);
	}
	return 0;
}