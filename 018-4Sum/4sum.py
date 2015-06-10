#!/bin/env python

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[][]}
    def fourSum(self, nums, target):
        nums.sort()
        nums_len = len(nums)
        if nums_len < 4:
            return []
        if target < sum(nums[0:4]) or sum(nums[nums_len - 4: nums_len]) < target:
            return []

        results = []
        for i in range(nums_len - 3):
            for j in range(i + 1, nums_len - 2):
                for t in range(j + 1, nums_len - 1):
                    delta = target - (nums[i] + nums[j] + nums[t])
                    if delta < nums[t+1] or nums[nums_len - 1] < delta:
                        continue
                    index = self.binarySearch(nums[t + 1:], 0, nums_len - t - 2, delta)
                    if index >= 0:
                        results.append((nums[i], nums[j], nums[t], nums[index + t + 1]))
        results = list(set(results))
        return results

    def binarySearch(self, nums, low, high, target):
        while low <= high:
            mid = (low + high) / 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1

s = Solution()
data = [1,0,-1,0,-2,2]
target = 0
print 'data:',data, ' target:', target
print s.fourSum(data, target)


