class Solution:
    # @param {string} digits
    # @return {string[]}
    def letterCombinations(self, digits):
        num2letter = {
                '2':['a', 'b', 'c'],
                '3':['d','e','f'],
                '4':['g','h','i'],
                '5':['j','k','l'],
                '6':['m','n','o'],
                '7':['p','q','r','s'],
                '8':['t','u','v'],
                '9':['w','x','y','z']}
        data = [num2letter[digit] for digit in digits] 
        return reduce(self.intersect, data, [None])

    def letterCombinations2(self, digits):
        num2letter = {
                '1':'',
                '2':'abc',
                '3':'def',
                '4':'ghi',
                '5':'jkl',
                '6':'mno',
                '7':'pqrs',
                '8':'tuv',
                '9':'wxyz'}
        #if len(digits) == 1:
        #    return num2letter[digits[0]]
        data = filter(lambda x:x!='', [num2letter[digit] for digit in digits])
        #print data
        #return [] if digits == "" else reduce(lambda x, y:reduce(lambda a,b:a+b, [[i+j for i in x] for j in y], []), data, [''])
        return [] if digits == "" else reduce(lambda x,y:reduce(lambda a,b:a+b, [[i + j for i in x] for j in y], []), data, [''])

    def intersect(self, list1, list2):
        result = []
        for i in list1:
            for j in list2:
                result.append(i + j)
        return result
        
s = Solution()
#print s.letterCombinations('')
print s.letterCombinations2('231')
print s.letterCombinations2('2')
print s.letterCombinations2('12')
print s.letterCombinations2('')
