#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re


# 统计每行字符数
def count_character(line):
    # character_num = len([i for i in list(line) if ord(i) <= 127])
    character_num = len(line)

    return character_num


# 统计每行单词数
def count_word(line, count):
    words = 0
    word = re.split(r'[^a-z0-9]+', line)
    pattern = re.compile(r'[a-z]{4}[a-z0-9]*')
    for w in word:
        if re.match(pattern, w):
            words += 1
            if w in count:
                count[w] += 1
            else:
                count[w] = 1

    return words


# 统计最多的10个单词及其词频
def count_most(count):
    ans = sorted(count.items(), key=lambda x: (-x[1], x[0]))
    result = {k: v for k, v in ans[:10]}

    return result
