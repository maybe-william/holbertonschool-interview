#!/usr/bin/python3
"""This file reads stdin line by line and computes metrics"""
import sys
import re
import signal


total_size = 0
code_nums = {}
line_num = 0


def sig_hand(sig, frame):
    """handle sigint"""
    print_stuff()


def print_stuff():
    """print file size and status code frequency"""
    print('File size: {}'.format(total_size))
    for i in sorted(code_nums.keys()):
        j = code_nums.get(i)
        print('{}: {}'.format(i, j))


for line in sys.stdin:
    if line == "":
        continue
    valid_codes = "(200|301|400|401|403|404|405|500)"
    patt = re.compile("^.*\s+" + valid_codes + "\s+(\d+)\s*$")
    x = patt.match(line)
    patt = re.compile("^.*\s+(\d+)\s*$")
    y = patt.match(line)
    if (y):
        size = y[1]
        total_size = total_size + int(size)
    if (x):
        code = x[1]
        code_nums[code] = code_nums.get(code, 0) + 1
    line_num = line_num + 1
    if line_num == 10:
        line_num = 0
        print_stuff()
    signal.signal(signal.SIGINT, sig_hand)
print_stuff()
