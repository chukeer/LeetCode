class Solution:
    # @param {string} s
    # @return {integer}

    def romanToInt(self, s):
        base_rom = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000} 
        result = 0
        last_value = 0
        for c in s:
            cur_value = base_rom[c]
            if cur_value == last_value * 5 or cur_value == last_value * 10:
                result = result + cur_value - last_value * 2
            else:
                result = result + cur_value
            last_value = cur_value
        return result

s = Solution()
print s.romanToInt('MMMCMXCIX') # 3999
print s.romanToInt('MCMLXXVI') # 1976
print s.romanToInt('X') # 10
#print s.romanToInt('MDXXVII')

