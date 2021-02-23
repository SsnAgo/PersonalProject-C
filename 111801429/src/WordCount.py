#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

input_file = sys.argv[1]
output_file = sys.argv[2]

# 打开输入文件
with open(input_file, encoding='utf-8') as f:
    content = f.read()
    print(content)

# 打开输出文件
with open(output_file, 'w', encoding='utf-8') as f:
    f.write("it's ok!")
