#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import re

input_file = sys.argv[1]
output_file = sys.argv[2]

# 打开输入文件
characters = 0
words = 0
lines = 0
count = {}
with open(input_file, encoding='utf-8') as f:
    for line in f:
        line = line.lower()

        character_num = len([i for i in list(line) if ord(i) <= 127])
        characters += character_num

        if not line.isspace():
            lines += 1

        word = re.split(r'[^a-z0-9]', line)
        pattern = re.compile(r'[a-z]{4}[a-z0-9]*')
        for w in word:
            if re.match(pattern, w):
                words += 1
                if w in count:
                    count[w] += 1
                else:
                    count[w] = 1


# 打开输出文件
with open(output_file, 'w', encoding='utf-8') as f:
    f.write("characters: {0}\n".format(characters))
    f.write("words: {0}\n".format(words))
    f.write("lines: {0}\n".format(lines))

    count = sorted(count.items(), key=lambda x: (-x[1], x[0]))
    for k, v in count[:10]:
        f.write("{0}: {1}\n".format(k, v))
