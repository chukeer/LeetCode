#!/bin/env python
import sys
from math import fabs
class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def threeSumClosest(self, nums, target):
        nums.sort()
        nums_len = len(nums)
        if nums_len < 3:
            return 0
        if target < sum(nums[0:3]):
            return sum(nums[0:3])
        if sum(nums[nums_len-3:nums_len]) < target:
            return sum(nums[nums_len-3:nums_len])

        result = sys.maxint
        for i in range(nums_len - 2):
            for j in range(i + 1, nums_len - 1):
                    delta = target - (nums[i] + nums[j])
                    if delta <= nums[j+1]:
                        tmp_value = nums[j+1]
                    elif nums[nums_len-1] <= delta:
                        tmp_value = nums[nums_len-1]
                    else:
                        #tmp_nums = list(set(nums[j+1:]))
                        index = self.binarySearchMinDeltaIndex(nums[j+1:], 0, nums_len - j - 2, delta)
                        #index = self.binarySearchMinDeltaIndex(tmp_nums, 0, len(tmp_nums) - 1, delta)
                        #print 'search ', delta, ' in num:', nums[j+1:]
                        #tmp_value = tmp_nums[index]
                        tmp_value = nums[index + j + 1]
                    tmp_result = nums[i] + nums[j] + tmp_value
                    if fabs(target - tmp_result) < fabs(target - result):
                        result = tmp_result
                        if result == target:
                            return result
                    #print 'search ', nums[i], nums[j],' delta:', delta,  ' [',index ,']:', nums[index], ' target:', target, ' result:', result

        return result

    def binarySearchMinDeltaIndex(self, nums, low, high, val):
        if nums[high] <= val:
            return high
        if val <= nums[low]:
            return low
        if high - low == 1:
            if val - nums[low] < nums[high] - val:
                return low
            else:
                return high
        mid = (low + high) / 2
        if (nums[mid] == val):
            return mid;
        elif (nums[mid] < val):
            return self.binarySearchMinDeltaIndex(nums, mid, high, val)
        else:
            return self.binarySearchMinDeltaIndex(nums, low, mid, val)

s = Solution()
#data = [-1, 2, 1, -4]
data = [0,0,0]
target = 1
#data = [43,75,-90,47,-49,72,17,-31,-68,-22,-21,-30,65,88,-75,23,97,-61,53,87,-3,33,20,51,-79,43,80,-9,34,-89,-7,93,43,55,-94,29,-32,-49,25,72,-6,35,53,63,6,-62,-96,-83,-73,66,-11,96,-90,-27,78,-51,79,35,-63,85,-82,-15,100,-82,1,-4,-41,-21,11,12,12,72,-82,-22,37,47,-18,61,60,55,22,-6,26,-60,-42,-92,68,45,-1,-26,5,-56,-1,73,92,-55,-20,-43,-56,-15,7,52,35,-90,63,41,-55,-58,46,-84,-92,17,-66,-23,96,-19,-44,77,67,-47,-48,99,51,-25,19,0,-13,-88,-10,-67,14,7,89,-69,-83,86,-70,-66,-38,-50,66,0,-67,-91,-65,83,42,70,-6,52,-21,-86,-87,-44,8,49,-76,86,-3,87,-32,81,-58,37,-55,19,-26,66,-89,-70,-69,37,0,19,-65,38,7,3,1,-96,96,-65,-52,66,5,-3,-87,-16,-96,57,-74,91,46,-79,0,-69,55,49,-96,80,83,73,56,22,58,-44,-40,-45,95,99,-97,-22,-33,-92,-51,62,20,70,90]
#target = 284
print 'data:',data, ' target:', target
print s.threeSumClosest(data, target)
#print s.binarySearchMinDeltaIndex(data, 0, len(data) - 1, 2)


