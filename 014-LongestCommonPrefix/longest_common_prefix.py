class Solution:
    # @param {string[]} strs
    # @return {string}
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ''
        tail = 0
        while True:
            c = ''
            is_same = True
            for str in strs:
                if len(str) <= tail:
                    is_same = False
                    break
                if c == '':
                    c = str[tail]
                elif str[tail] != c:
                    is_same = False
                    break
            if not is_same:
                break
            tail = tail + 1
        return strs[0][0:tail]
                    
s = Solution()
print s.longestCommonPrefix(['abc', 'abcde', 'abxx'])
print s.longestCommonPrefix(['abc', 'abcde', ''])
