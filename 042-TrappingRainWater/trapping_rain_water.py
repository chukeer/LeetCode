class Solution:
    def __init__(self):
        max_left = 0
        max_right = 0
    # @param {integer[]} height
    # @return {integer}
    def trap(self, height):
        height_len = len(height)

        # 对每个bar，找其左边最大值
        max_left = 0
        max_left_height = [0] * height_len
        for index in range(height_len):
            if index == 0:
                max_left_height[index] = 0
            else:
                max_left = max_left if max_left >= height[index-1] else height[index-1]
                max_left_height[index] = max_left

        # 对每个bar，找其右边最大值
        max_right = 0
        max_right_height = [0] * height_len
        for index in range(height_len)[::-1]:
            if index == height_len - 1:
                max_right_height[index] = 0
            else:
                max_right = max_right if max_right >= height[index+1] else height[index+1]
                max_right_height[index] = max_right

        # 计算每个bar的积水
        area = 0
        for index, h in enumerate(height):
            if min(max_left_height[index], max_right_height[index]) <= h:
                continue
            else:
                area = area + min(max_left_height[index], max_right_height[index]) - h

        return area

s = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print s.trap(height)