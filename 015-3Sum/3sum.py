class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def threeSum(self, nums):
        d = {} # value: ([num1, num2], num1_index, num2_index)
        d_count = {}
        for num in nums:
            if d_count.has_key(num):
                d_count[num] = d_count[num] + 1
            else:
                d_count[num] = 1
        nums = list(set(tuple(nums)))
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if i == j:
                    if d_count[nums[i]] == 1:
                        continue
                delta = 0 - (nums[i] + nums[j])
                v = ([nums[i], nums[j]], i, j)
                if d.has_key(delta):
                    d[delta].append(v)
                else:
                    d[delta] = [v]
        results = []
        if d_count[0] >= 3:
            results.append((0,0,0))
        if d_count[0] >= 2:
            d_count[0] = 1
        for i in range(len(nums)):
            num = nums[i]
            value_list = d.get(num, None)
            if value_list:
                # add to the left
                for value, index1, index2 in value_list:
                    if (i == index1 or i == index2) and d_count[nums[i]] == 1:
                        continue
                    value = [num] + value
                    value.sort()
                    results.append(value)
                
                #print tmp_value
                #results = results + list(set(tmp_value))
        return list(set([tuple(x) for x in results]))



s = Solution()
print s.threeSum([13,-4,1,3,-1,-1,5,-11,13,9,4,7,5,-5,-13,-4,8,-3,14,-4,14,6,7,11,4,-6,-5,-9,14,3,-9,12,-15,0,-8,-9,14,4,-5,4,-1,-15,-12,-11,-13,-9,1,3,-5,0,14,-6,13,-1,12,2,8,-7,9,0,11,7,-11,3,-8,-11,1,13,8,4,-5,14,4,-2,11,-2,-4,-3,-14,6,4,8,7,3,-8,5,12,7,5,-2,-8,-7,13,-11,12,12,-7,-10,11,-14])

