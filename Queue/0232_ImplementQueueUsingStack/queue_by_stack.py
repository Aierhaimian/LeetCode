#!/usr/bin/env python3
# -*-coding: utf-8 -*-
"""

Version: 0.1
Author: Earl
"""

"""
Time  Complexity: O(2n)
Space Complexity: O(2n)
"""
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        input_stack = []
        output_stack = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        input_stack.append(x);

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        tmp = peek()
        output_stack.pop()
        return tmp

    def peek(self) -> int:
        """
        Get the front element.
        """
        if not output_stack:
            while input_stack:
                output_stack.append(input_stack.pop())
        return output_stack[-1]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return (not input_stack) and (not output_stack)


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()

if __name__ == "__main__":



