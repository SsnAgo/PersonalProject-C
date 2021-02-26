#include "lib.h" 
void WordCount::start()
{
	ifstream file(input_file);      //Read the current folder input.txt file
    FILE *fp;
	fopen_s(&fp, input_file, "r");
	WordCount A(fp, input_file, output_file);
	ofstream outfile(output_file, ios::out);
	if (!outfile) {
		cerr << "create error!" << endl;
		exit(1);
	}outfile.close();
}