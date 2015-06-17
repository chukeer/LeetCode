class Solution:
    # @param {integer} n
    # @return {string}
    def countAndSay(self, n):
        if n <= 0:
            return ""
        if n == 1:
            return "1"
        else:
            result = '1'
            for i in range(n - 1):
                result = self.getNext(result)
        return result

    def getNext(self, s):
        count = 0
        last = ''
        result = []
        for char in s:
            #print 'char:', char
            if char != last:
                if last != '':
                    result.append(str(count) + last)
                count = 1
            else:
                count = count + 1
#            print 'last:', last, ' count:', count
            last = char
        if count > 0:
            result.append(str(count) + last)
        return ''.join(result)

s = Solution()
print '3:', s.countAndSay(3)
print '4:', s.countAndSay(4)
print '5:', s.countAndSay(5)
print '7:', s.countAndSay(7)
