#!/usr/bin/python3
"""This file reads stdin line by line and computes metrics"""
import sys
import re
import signal


if __name__ == "__main__":
    total_size = 0
    code_nums = {}
    line_num = 0
    print('File size: 0')

    def print_stuff():
        """print file size and status code frequency"""
        if (file_size > 0):
            print('File size: {}'.format(total_size))
            for i in sorted(code_nums.keys()):
                j = code_nums.get(i)
                print('{}: {}'.format(i, j))

    try:
        for line in sys.stdin:
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
    except KeyboardInterrupt:
        print_stuff()
        raise
    print_stuff()
