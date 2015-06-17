class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum2(self, candidates, target):
        results = self.combinationSumRecursion(candidates, target)
        return self.uniqList(results)

    def combinationSumRecursion(self, candidates, target):
        results = []
        for item in candidates:
            if item == target:
                results.append([item])
        candidates = filter(lambda x: x < target, candidates)
        candidates_len = len(candidates)
        for i in range(candidates_len):
            #tmp_candidates = candidates[0:i] + candidates[i + 1:]
            tmp_candidates = candidates[i + 1:]
            tmp_results = self.combinationSumRecursion(tmp_candidates, target - candidates[i]);
            results += [[candidates[i]] + x for x in tmp_results]

        return results

    def uniqList(self, results):
        uniq_results = []
        for item in results:
            item.sort()
            uniq_results.append(tuple(item))
        uniq_results = set(uniq_results)
        return [list(x) for x in uniq_results]

#pdb.set_trace()
s = Solution()
#candidates = [10,1,2,7,6,1,5]
#target = 8
#candidates.sort()
candidates = [13, 23, 25, 11, 7, 26, 14, 11, 27, 27, 26, 12, 8, 20, 22, 34, 27, 17, 5, 26, 31, 11, 16, 27, 13, 20, 29,
              18, 7, 14, 13, 15, 25, 25, 21, 27, 16, 22, 33, 8, 15, 25, 16, 18, 10, 25, 9, 24, 7, 32, 15, 26, 30, 19]
target = 25

print 'candidates:', candidates, ' target:', target
print 'result:', s.combinationSum2(candidates, target)
