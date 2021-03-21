#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>

/*
函数名:ParseArgs
描述:解析命令行参数。
参数:@argc:命令行参数
	 @argv:命令行参数
返回:@int:如果解析正确则为0，否则为-1并显示信息。
*/

int ParseArgs(int argc, char **argv);

