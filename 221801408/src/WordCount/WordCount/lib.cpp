#include "lib.h" 
void WordCount::start()
{
	ifstream file(input_file);      //读取文件目录下的input.txt文件
    FILE *fp;
	fopen_s(&fp, input_file, "r");
	WordCount A(fp, input_file, output_file);
	ofstream outfile(output_file, ios::out);
	if (!outfile) {
		cerr << "创建失败！" << endl;
		exit(1);
	}outfile.close();
}