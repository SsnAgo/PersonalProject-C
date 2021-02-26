#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
from Lib import *


try:
    # 获取输入输出文件名
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    # 数据初始化
    characters = 0
    words = 0
    lines = 0
    count = {}

    # 打开输入文件
    with open(input_file, encoding='utf-8', newline='') as f:
        for line in f:
            line = line.lower()

            # 统计每行字符数
            characters += count_character(line)

            # 统计非空白行数
            if not line.isspace():
                lines += 1

            # 统计每行单词数
            words += count_word(line, count)

    # 打开输出文件
    with open(output_file, 'w', encoding='utf-8', newline='') as f:
        f.write("characters: {0}\n".format(characters))
        f.write("words: {0}\n".format(words))
        f.write("lines: {0}\n".format(lines))

        # 输出最多的10个单词及其词频
        result = count_most(count)
        for k, v in result.items():
            f.write("{0}: {1}\n".format(k, v))

except IndexError:
    print("未指明输入/输出文件")
except FileNotFoundError:
    print("找不到输入文件{0}".format(input_file))
except:
    info = sys.exc_info()
    print(info[1])
