# -*- coding: utf-8 -*
import sys
class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @resulturn {string}
    '''
    假设输入字符串为ABCDEFGH，按如下方式排列
    A     G
    B   F H
    C E
    D
    先补全，使其成为完整周期，没有字符的地方用*占位
    A     G
    B   F H   *
    C E   * *
    D     * 
    以ABCDEF为一个周期
    这种情况下，会用到如下参数
    T_num    is 6, 每个周期的字符数量
    T_count  is 2, 周期数
    T_width  is 3, 周期矩阵的宽
    T_height is 4, 周期矩阵的高
    然后按AGBFH*CE**D*的索引顺序遍历，先求出在补全后的二维数组里的row和col
    然后求对应在原字符串里的index
    这样可直接遍历一遍就计算出结果
    '''
    def convert(self, s, numRows):
        if numRows == 1:
            return s
        str_len = len(s)
        T_num = numRows + numRows - 2
        T_count = str_len / T_num + 1
        T_width = numRows - 1
        T_height = numRows
        full_str = s + (T_num * T_count - len(s)) * ' '
        #print 'T_num:', T_num, ' T_count:', T_count, ' full_str:', full_str, ' len:',len(full_str)
        result = ''
        full_str_len = len(full_str)
        for i in xrange(full_str_len):
            if i < T_count:
                row = 0
                col = i * T_width
            elif i >= T_count * (T_num - 1):
                row = T_height - 1
                col = (i - (T_count * (T_num - 1))) * T_width
            else:
                row = 1 + (i - T_count) / (T_count * 2)
                tmp = (i - T_count) % (T_count * 2)
                if tmp % 2 == 0:
                    col = (tmp / 2) * T_width
                else:
                    col = (tmp % (2 * T_count) / 2) * T_width + (T_height - row -1)
            #print 'i:', i, ' row:', row, ' col:', col
            T_index = col / T_width
            if col % T_width == 0:
                T_mod = row + 1
            else:
                T_mod = col % T_width + T_height
            index = T_index * T_num + T_mod - 1
            #print 'T_index:', T_index
            if full_str[index] != ' ':
                result = result + full_str[index]
        return result

s = Solution()
print s.convert('wjkakhxhsglmmhstrwgulfztwhhjlbihmviwehfwntibadvubdomiphgxpsiscsexccbjhazakadnvxqanelemtbdlmvoezlgbprkpqlbtqpqphrcmcgyvkbhwyvcxikazbkquxsnpjdeqwicyrcwbfdzdabcklcmmpciouvedbiwxryyidulizkmblonwtzkkcvayqectpariyrqdldmmnynaoawjaivedwcwcgrrgibhbtkmwwyjwnjnohyqsuuxqwvufnmlxnszhfnfbmpabaprknhchdzzaxufkishxngeswkvkbvlbkdlamphqrhsodzylrhieqpymbuwcrhfemtezklpbuhrxgpkzzvgpkedlyzpqiwuvrywelnfguxfcosdpnjexohkoiberzaotymxmzeuvdbzutcjimqhcxrqiuxbwxrpydokcsgxwhwqdazloptqpmjzjgafftwdwkpacxzafxqkxsvmjqeadpbmvbtbupgsbysdvtecqwmqqiecaicdyervhkyebhwcfricmofdmttddxfehjhhnbdxnbbpiztpsdufrzkeudjycqcjzltpmwmczprkqmblqvqjwcnrfypjotuoenftlrvlioxycylsubcqfrhksyvgrqwyfbtruqecgbdibodvshoxaxksyhbrxxrfbkyvccaifftgtwendulfrxyrebjeaajbljzplzyseryzpenuyazszxldyujzvucidbxqcxiiqjifnxbozbiyatdzqpaljevpisfksovkxfqmctcdumdviiwyxwljcgykadvsrsdqxvfbojelwjgercerapacvypxdmqxevpbsucieitctbikdmdfdfkydzvjlngpkvqcsunyeiaxkijnwnvzsfzyewhpkpewmwbeqocwwetgmcwkrrjkwikahtrtivpurqbjgffdkalwcjjuasgydqamjrftmupfnqqtwxyixmgavp', 621)
#print s.convert('abcde', 4)
##print s.convert('PAYPALISHIRING', 3)
