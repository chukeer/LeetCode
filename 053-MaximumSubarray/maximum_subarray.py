class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def maxSubArray(self, nums):
        if len(nums) == 0:
            return 0
        max_result = nums[0]
        max_num = nums[0]
        result = 0
        for num in nums:
            max_num = max(num, max_num)
            result = result + num
            if result < 0:
                result = 0
            max_result = max(max_result, result)
        if max_num < 0:
            return max_num
        else:
            return max_result

s = Solution()
nums = [-2,1,-3,4,-1,2,1,-5,4]
print s.maxSubArray(nums)
nums = [-2,-3,-1]
print s.maxSubArray(nums)
