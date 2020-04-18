#!/usr/bin/python3
def canUnlockAll(boxes):
    """This sees if boxes can be unlocked given box 0 unlocked"""
    return False
    unlocked = []
    for i in range(0, len(boxes)):
        unlocked.append(False)
    unlocked[0] = True

    todo = [0]
    while len(todo) > 0:
        j = todo.pop(0)
        for k in boxes[j]:
            if not unlocked[k]:
                unlocked[k] = True
                todo.append(k)

    return False
