#!/usr/bin/python3
"""This file reads stdin line by line and computes metrics"""
import re
import signal
import sys


if __name__ == "__main__":
    total_size = 0
    code_nums = {}
    line_num = 0

    def print_stuff():
        """print file size and status code frequency"""
        print('File size: {}'.format(total_size))
        for i in sorted(code_nums.keys()):
            j = code_nums.get(i)
            print('{}: {}'.format(i, j))

    try:
        for line in sys.stdin:
            if line_num == 10:
                line_num = 0
                print_stuff()
            patt = re.compile(".*\".*\"\s+(.*)\s+(.*)")
            x = patt.match(line)
            code = x[1]
            size = x[2]
            total_size = total_size + int(size)
            code_nums[code] = code_nums.get(code, 0) + 1
            line_num = line_num + 1
    except KeyboardInterrupt:
        print_stuff()
        raise
    print_stuff()
