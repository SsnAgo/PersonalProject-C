#include "lib.h" 
int WordCount::charcount()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, input_file, "r");
	if (err != NULL)
	{
		printf("文件读取失败.");//文件读取失败提示
	}
	int allchar = 0;
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)//一个一个字符的读取 
	{
		allchar++;
		ch = fgetc(fp);
	}
	fclose(fp);
	return allchar;
}

void WordCount::start()
{
	ifstream file(input_file);      //读取文件目录下的input.txt文件
    FILE *fp;
	fopen_s(&fp, input_file, "r");
	WordCount A(fp, input_file, output_file);
	
	ofstream outfile(output_file, ios::out);
	outfile << "characters:" << ' ' << A.charcount() << endl;
	if (!outfile) {
		cerr << "创建失败！" << endl;
		exit(1);
	}outfile.close();
}