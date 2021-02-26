#include "lib.h" 
unordered_map<string, int> stringmap;
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
int WordCount::linecount()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, input_file , "r");
	if (err != NULL)
	{
		printf("文件读取失败.");//文件读取失败提示
	}
	int line = 0;
	char ch;
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (line == 0 && ch != ' '&&ch != '\n')//对第一行进行定义 由于第一行没有换行符
			line++;
		else if (ch == '\n')
		{
			line++;
			ch = fgetc(fp);
			if (ch == EOF)//怕只有一个换行符就结束了
				line--;

		}
		else
		{
			ch = fgetc(fp);
		}
	}

	fclose(fp);
	return line;
}
void getstring(stringstream &ss)//生成string中单词的键值对
{
	string strTmp;
	while (ss >> strTmp)
	{
		unordered_map<string, int>::iterator it = stringmap.find(strTmp);//以strTmp创建一个容器
		if (it == stringmap.end())
		{
			stringmap.insert(unordered_map<string, int>::value_type(strTmp, 1));
		}
		else
			stringmap[strTmp]++;
	}
}
int WordCount::wordnum()
{
	string strFile, tmp;
	int i = 0;
	ifstream file(input_file);      //读取当前文件夹下input.txt文件
	while (getline(file, tmp))//直到文件结尾，依次逐行读入文本
	{
		strFile.append(tmp); //每次读入一行附加到strFile结尾
		strFile.append(" ");//行尾补充空格
		tmp.clear();            //记得清除，否则上一次读入比这次文本长，不会完全覆盖而出错
	}
	for (int i = 0; i <= strFile.size(); i++)
	{

		if (strFile[i] >= 'A'&&strFile[i] <= 'Z')
			strFile[i] += 32;//将字母化为小写
	}
	for (int i = 0; i < strFile.length(); i++)
	{
		if (ispunct(strFile[i]))
			strFile[i] = ' '; //符号位替换成为空格
	}
	stringstream ss(strFile);

	if (stringmap.empty())
		getstring(ss);
	vector < pair < int, string > > v;
	for (unordered_map<string, int>::iterator it = stringmap.begin(); it != stringmap.end(); ++it)
		v.push_back(make_pair(it->second, it->first));//内将字序压入容器内
	for (unsigned int k = 0; k < v.size(); ++k)
	{
		string a = v[k].second.c_str();
		if (
			((a[0] >= 'a'&&a[0] <= 'z') || (a[0] >= 'A'&&a[0] <= 'Z')) &&
			((a[1] >= 'a'&&a[1] <= 'z') || (a[1] >= 'A'&&a[1] <= 'Z')) &&
			((a[2] >= 'a'&&a[2] <= 'z') || (a[2] >= 'A'&&a[2] <= 'Z')) &&
			((a[3] >= 'a'&&a[3] <= 'z') || (a[3] >= 'A'&&a[3] <= 'Z')))
		{
			i += v[k].first;//把键值加起来就行
		}
	}

	return i;

}
void WordCount::start()
{
	ifstream file(input_file);      //读取文件目录下的input.txt文件
    FILE *fp;
	fopen_s(&fp, input_file, "r");
	WordCount A(fp, input_file, output_file);
	ofstream outfile(output_file, ios::out);
	outfile << "characters:" << ' ' << A.charcount() << endl;
	outfile << "words:" << ' ' << A.wordnum() << endl;
	outfile << "lines:" << ' ' << A.linecount() << endl;
	if (!outfile) 
	{
		cerr << "创建失败！" << endl;
		exit(1);
	}
	outfile.close();
}