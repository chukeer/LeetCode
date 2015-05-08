class Solution:
    # @param {integer[]} height
    # @return {integer}
    def maxArea(self, height):
        max_area = 0
        tail = len(height) - 1
        begin = 0
        #print height
        while begin != tail:
            #print 'begin:', begin, ' tail:', tail, ' h[begin]:', height[i], ' h[tail]:', height[tail]
            if (height[tail] > height[begin]):
                area = height[begin] * (tail - begin)
                begin = begin + 1
            else:
                area = height[tail] * (tail - begin)
                tail = tail - 1
            if area > max_area:
                max_area = area
            #print 'area:', area, ' max_area:', max_area
        return max_area



    def findListIndex(self, list_sorted_by_index, begin, end, value):
        if begin == end:
            if list_sorted_by_index[begin][0] == value:
                return begin
            else:
                return -1
        mid = (begin + end) / 2
        if list_sorted_by_index[mid][0] == value:
            return mid
        elif list_sorted_by_index[mid][0] > value:
            return self.findListIndex(list_sorted_by_index, begin, mid - 1, value)
        else:
            return self.findListIndex(list_sorted_by_index, mid + 1, end, value)

    def maxArea2(self, height):
        max_area = 0
        for i in range(0, len(height)):
            for j in range(i + 1, len(height)):
                if height[i] > height[j]:
                    area = height[j] * (j - i)
                else:
                    area = height[i] * (j - i)
                if area > max_area:
                    max_area = area
                #print 'i:', i, ' j:', j, ' area:', area, ' max:', max_area
        return max_area



s = Solution()
#print s.maxArea([10,9,8,7,6])
print s.maxArea2([10,9,20,7,20])
print s.maxArea([10,9,20,7,20])
#print s.maxArea([7,9,8,10,100])
