#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

const int MAX_LEN_STR = 100;	// �����ַ�������󳤶� 

typedef struct word_info{		// �ṹ�壺���ʼ�¼ 
	char word[MAX_LEN_STR+1];	// ���� 
	int  n_word_repeat;			// �����ظ��Ĵ��� 
}WInfo;

typedef struct words_record{	// �ṹ�壺���ʼ�¼ 
	WInfo words[501];			// ���е��� 
	int n_word_count;			// ���ʵ����� 
}WRec;

bool is_digit(char ch);			// �ж�ch�Ƿ���һ�������ַ� 
bool is_alpha(char ch);			// �ж�ch�Ƿ���һ����ĸ 
char lowercase(char ch);		// ��chת��ΪСд 
void add_word_to_(WRec &records, const char* word);			// ��word�ӵ�records�� 
void sort_WRec(WRec &records);								// ����Ƶ�ʺ��ֵ�˳������ 
void wodrcount(const char* in_file, const char* out_file);	// �������ļ�in_file����ͳ�ƣ������out_file


int main(int argc, const char* argv[]) {
	
	if(argc != 3){		// ������������Ϊ3 
		
		printf("Usage: %s [input_file] [output_file]\n", argv[0]);
		return 1;
	}
	
	wodrcount(argv[1], argv[2]);
	
	return 0;
}


bool is_digit(char ch) {
	
	return (ch >= '0' && ch <= '9');
}

bool is_alpha(char ch) {
	
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ;
}

char lowercase(char ch) {
	
	if(ch >= 'A' && ch <= 'Z')	// ��д��ĸ��ascall��32���ڶ�Ӧ��Сд��ĸ 
		return ch+32;
								// ������Ǵ�д��ĸ������ԭ����ֵ 
	return ch;
}

bool is_word(const char* str) {
	
	int alpha_count = 0;	// ��ͷ������ĸ�ĸ���
	
	if(is_digit(*str))		// �����һ���������ַ������ǵ��� 
		return false;

	// �����ַ��� 
	for(const char *p = str; *p != '\0'; p ++) {
		
		if(is_alpha(*p))			// ������ַ�����ĸ��+1 
			alpha_count++;
		else if(alpha_count < 4)	// ������һ������ĸ�ַ�ʱ���������4�������ǵ��� 
			return false;
			
		if(alpha_count >= 4)
			return true;
	}
	return false;
}

void add_word_to_(WRec &records, const char* word) {
	
	for(int i = 0; i < records.n_word_count; i ++) {
		
		// ������ظ����ʣ��ظ�����+1 
		if(strcmp(word, records.words[i].word) == 0) {
			
			records.words[i].n_word_repeat ++;
			return;
		}
	}
	
	// ������Ϊ�µĵ������ 
	strcpy(records.words[records.n_word_count].word, word);
	records.words[records.n_word_count].n_word_repeat = 1;
	records.n_word_count ++;
}

void sort_WRec(WRec &records) {
	
	WInfo temp;
	
	for(int i = 0; i < records.n_word_count-1; i ++) {
		
		for(int j = 0; j < records.n_word_count-1-i; j ++) {
			
			// ���ʵ�Ƶ�ʸ��󣬻�������ͬ���ֵ���ߵķ�ǰ 
			if(records.words[j].n_word_repeat < records.words[j+1].n_word_repeat
			|| records.words[j].n_word_repeat == records.words[j+1].n_word_repeat && strcmp(records.words[j].word, records.words[j+1].word) > 0) {
				
				temp = records.words[j];
				records.words[j] = records.words[j+1];
				records.words[j+1] = temp;
			}
		}
	}
}

void wodrcount(const char* in_file, const char* out_file) {
	
	ifstream input;			// �����ļ� 
	ofstream output;		// ����ļ� 
	int      n_line = 0;	// �ǿ����� 
	int   	 n_word = 0;	// ������ 
	int   	 n_char = 0;	// �ַ��� 
	WRec 	 records;		// ���е��ʼ�¼ 
	char 	 last_ch = '\0';// ��һ����ȡ���ַ� 
	char 	 ch;			// ��ȡ���ַ� 
	char 	 buf[501];		// ������ 
	char 	 word_buf[MAX_LEN_STR+1];	// ���ʻ����� 
	int  	 word_len = 0;	// ���ʳ��� 
	bool 	 line_empty;	// ���Ƿ�Ϊ�� 
	
	int cur_line = 0; 
	
	input.open(in_file,ios::binary);
	if(!input.is_open() || input.bad()){
		
		printf("�ļ�%s��ʧ��\n", in_file);
		return;
	}
	
	records.n_word_count = 0;	// ��ʼ������Ϊ0 
	
	n_line = 1;
	line_empty = true;
	while(!input.eof()) {		// ��ȡ���ļ�β 
		
		ch = input.get();
		if(ch == EOF || ch == '\0'){
			
			if(n_char == 0){
				
				n_line = 0;
			}
			break;
		}

		n_char ++;
		if(ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {		// �������ַ�ʱ�����зǿ� 
			
			line_empty = false;
		}
		if(is_digit(ch) || is_alpha(ch)){	// ������ĸ�������ַ�����ʼ���԰����ʶ��� 
			
			word_buf[word_len++] = lowercase(ch);
		}
		else if(word_len > 0 && (is_digit(last_ch) || is_alpha(last_ch))){	// ��ǰ�ַ���Ϊ��ĸ�������ַ�������һ���ַ���ʱ 
			
			word_buf[word_len] = '\0';
			word_len = 0;
			if(is_word(word_buf)){
				
				add_word_to_(records, word_buf);
				n_word++;
			}
		}
		
		if(ch == '\n'){
			
			if(!line_empty)
				n_line++;
			line_empty = true;
		}
		last_ch = ch;
	}
	input.close();
	if(line_empty)
		n_line--;
	if(word_len > 0 && (is_digit(last_ch) || is_alpha(last_ch))){	// ��ǰ�ַ���Ϊ��ĸ�������ַ�������һ���ַ���ʱ 
			
		word_buf[word_len] = '\0';
		word_len = 0;
		if(is_word(word_buf)){
			
			add_word_to_(records, word_buf);
			n_word++;
		}
	}
	sort_WRec(records);
	
	// �����ָ������ļ� 
	output.open(out_file);
	if(!output.is_open() || output.bad()){
		
		printf("�ļ�%s��ʧ��\n", out_file);
		return;
	}
	sprintf(buf, "characters: %d\nwords: %d\nlines: %d\n", n_char, n_word, n_line);
	output << buf;
	for(int i = 0; i < 10; i ++) {
		
		sprintf(buf, "%s: %d\n", records.words[i].word, records.words[i].n_word_repeat);
		output << buf;
	}
	output.close();
}

