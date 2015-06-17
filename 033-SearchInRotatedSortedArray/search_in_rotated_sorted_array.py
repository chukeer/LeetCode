# -*- coding:utf-8 -*-
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def search(self, nums, target):
        nums_len = len(nums)
        if nums_len == 0:
            return -1
        if nums_len == 1:
            return 0 if nums[0] == target else -1
        return self.binarySearchRotatedArray(nums, 0, nums_len-1, target)

    def binarySearchRotatedArray(self, nums, begin, end, target):
        if begin == end:
            return begin if nums[begin] == target else -1
        mid = (begin + end) / 2
        if nums[mid] == target:
            return mid
        if nums[begin] <= nums[mid]:
            # 左部分为升序
            if target >= nums[begin] and target < nums[mid]:
                end = mid - 1
            else:
                begin = mid + 1
        else:
            # 右部分为升序
            if target > nums[mid] and target <= nums[end]:
                begin = mid + 1
            else:
                end = mid - 1

        return self.binarySearchRotatedArray(nums, begin, end, target)

s = Solution()
print s.search([4,5,6,7,0,1,2], 2)
print s.search([5,1,3], 3)