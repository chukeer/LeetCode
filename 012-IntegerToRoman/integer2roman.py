class Solution:
    # @param {integer} num
    # @return {string}
    def __init__(self):
        base_rom = {1:'I',5:'V',10:'X',50:'L',100:'C',500:'D',1000:'M'}
        self.int2rom = {}
        for base in [1, 10, 100, 1000]:
            for i in range(base, 10 * base, base):
                if i > 3999:
                    break
                count = i / base
                if count <= 3:
                    self.int2rom[i] = base_rom[base] * count
                elif count == 4:
                    self.int2rom[i] = base_rom[base] + base_rom[5 * base]
                elif count < 9:
                    self.int2rom[i] = base_rom[5 * base] + (count - 5) * base_rom[base]
                else:
                    self.int2rom[i] = base_rom[base] + base_rom[10 * base]

    def intToRoman(self, num):
        results = []
        base = 1
        while num > 0:
            value = (num % 10) * base
            if value != 0:
                results.append(self.int2rom[value])
            num = num / 10
            base = base * 10
        return ''.join(results[::-1])
        


s = Solution()
for i in range(1, 4000):
    print i,s.intToRoman(i)
