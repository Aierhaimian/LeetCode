#!/usr/bin/env python3
# -*-coding: utf-8 -*-
"""

Version: 0.1
Author: Earl
"""

"""
Time  Complexity: O(n)
Space Complexity: O(n)
"""
def isVaild(s):
    stack = []
    paren_map = {')':'(', ']':'[', '}':'{'}
    for c in s:
        if c not in paren_map:
            stack.append(c)
        elif not stack or paren_map[c] != stack.pop():
            return False
    return not stack

if __name__ == "__main__":
    print(isVaild("()"))
    print(isVaild("([)]"))
    print(isVaild("((([])))"))


