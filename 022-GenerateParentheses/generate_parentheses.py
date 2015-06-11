import copy
class Solution:
    # @param {integer} n
    # @return {string[]}
    def generateParenthesis(self, n):
        results = []
        for i in range(n):
            results = self.addParenthesis(results)
        return results

    def addParenthesis(self, s):
        if len(s) == 0:
            return ["()"]
        results = []
        for str in s:
            #print 'str:',str
            for i, c in enumerate(str):
                #print 'i:', i, ' c:', c
                if c == '(':
                    tmp_str = str[0:i] + '(' + str[i:]
                    #print 'after insert ( :', tmp_str
                    for j in range(i, len(tmp_str)):
                        if tmp_str[j] == '(':
                            tmp_result = tmp_str[0:j+1] + ')' + tmp_str[j+1:]
                            #print 'tmp_result:', tmp_result
                            results.append(tmp_result)
        return list(set(results))

s = Solution()
print '1 parenthis:', s.generateParenthesis(1)
print '2 parenthis:', s.generateParenthesis(2)
print '3 parenthis:', s.generateParenthesis(3)

