#include<iterator>
#include<cctype>
#include<ctype.h>
#include<unordered_map>
#include<algorithm>
#include<iostream>



using namespace std;

int main(int argc, char *argv[])
{
	const char* filename2;
	const char* filename;

	if (argc == 3)
	{
		filename = argv[1];
		filename2 = argv[2];
	}
	else
	{
		cerr << "输入参数失败!" << endl;
		exit(1);
	}
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "r");
	if (err != 0)
	{
		cerr << "打开失败!" << endl;
		exit(1);
	}
	


	fclose(fp);

	return 0;
}