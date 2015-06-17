# -*- coding:utf-8 -*-
class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def clear(self):
        del self.items[:]

    def empty(self):
        return self.size() == 0

    def size(self):
        return len(self.items)

    def top(self):
        return self.items[self.size()-1]

class Solution:
    # @param {string} s
    # @return {integer}
    def longestValidParentheses(self, s):
        list_str = []
        for index, c in enumerate(s):
            list_str.append([index, c, 0])
        stack = Stack()
        for index, c, flag in list_str:
            if stack.size() > 0:
                top_item = stack.top()
                if c == ')' and top_item[1] == '(':
                    # 出栈，并对该字符做标记
                    list_str[index][2] = 1
                    list_str[top_item[0]][2] = 1
                    stack.pop()
                else:
                    # 入栈
                    stack.push([index, c, flag])
            else:
                stack.push([index, c, flag])

        # 找出连续标记为1的字符串长度
        max_len = 0
        cur_len = 0
        for index, c, flag in list_str:
            if flag == 1:
                cur_len = cur_len + 1
            else:
                if cur_len > max_len:
                    max_len = cur_len
                cur_len = 0
        return max_len if max_len > cur_len else cur_len

s = Solution()
#print s.longestValidParentheses(')()())')
print s.longestValidParentheses('(()')