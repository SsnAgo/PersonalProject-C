#include <iostream>
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

void summarize(const char* in_file, const char* out_file);	  // �������ļ�in_file����ͳ�ƣ������out_file

int main(int argc, const char* argv[]) {
	
	if(argc != 3){		// ������������Ϊ3 
		
		printf("Usage: %s [input_file] [output_file]\n", argv[0]);
		return 1;
	}
	
	summarize(argv[1], argv[2]);
	
	return 0;
}

bool is_digit(char ch) {
	
	return (ch >= '0' && ch <= '9');
}

bool is_alpha(char ch) {
	
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ;
}

void summarize(const char* in_file, const char* out_file) {
	
	ifstream input;			// �����ļ� 
	ofstream output;		// ����ļ� 
	int      n_line = 0;	// �ǿ����� 
	int   	 n_word = 0;	// ������ 
	int   	 n_char = 0;	// �ַ��� 
	WRec 	 records;		// ���е��ʼ�¼ 
	char 	 buf[1024];		// ������ 
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
						
	while(!input.eof()) {		// ��ȡ���ļ�β 
		
		input.getline(buf, 1024);	// ��ȡ���� 
		if(!input.eof())
			n_char ++;
		line_empty = true;
		
		for(char* p = buf; *p != '\0'; p ++) {	// ���������е�ÿ���ַ� 
			
			n_char ++;
			if(*p != ' ' && *p != '\t') {		// �������ַ�ʱ�����зǿ� 
				
				line_empty = false;
			}
		}
	}
		
	input.close();

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
