#!/usr/bin/python3
""" Check how much rainfall is caught by an array """


def rain(walls):
    """ Check how much rain will stay within the array walls """

    if type(walls) is not list or len(walls) <= 2:
        return 0

    total = 0
    left_wall = 0
    right_wall = 1
    while(right_wall < len(walls) - 1):
        while(walls[right_wall] == 0 and right_wall < len(walls) - 1):
            right_wall = right_wall + 1
        water = (right_wall - left_wall - 1) * min(walls[left_wall],
                                                   walls[right_wall])
        total = total + water
        left_wall = right_wall
        right_wall = right_wall + 1

    return total


