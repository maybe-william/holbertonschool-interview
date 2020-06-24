#!/usr/bin/python3
"""This module validates utf8 bytes"""


def my_and(num, ones, zeros):
    """Make sure a number has ones and zeros in the right spots"""
    x = num & ones
    y = (~num) & zeros
    return (x == ones and y == zeros)


def verify_byte(byte, style=1):
    """Verifies the byte, returns true if valid, false if not valid"""
    if byte > 255 or byte < 0:
        return False
    if style == 1:
        return byte < 128
    elif style == 2:
        return my_and(byte, 192, 32)
    elif style == 3:
        return my_and(byte, 224, 16)
    elif style == 4:
        return my_and(byte, 240, 8)
    elif style == 5:
        return my_and(byte, 128, 64)


def validUTF8(data):
    """Given an array of bytes, determine whether or not it's valid UTF8"""
    if len(data) == 0:
        return True
    numOfFiller = 0
    for byte in data:
        if numOfFiller > 0:
            tmp = verify_byte(byte, 5)
            numOfFiller = numOfFiller - 1
            if not tmp:
                return False
        else:
            if verify_byte(byte, 1):
                numOfFiller = 0
            elif verify_byte(byte, 2):
                numOfFiller = 1
            elif verify_byte(byte, 3):
                numOfFiller = 2
            elif verify_byte(byte, 4):
                numOfFiller = 3
            else:
                return False

    if numOfFiller > 0:
        return False
    return True
