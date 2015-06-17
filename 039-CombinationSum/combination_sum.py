class Solution:
    # @param {integer[]} candidates
    # @param {integer} target
    # @return {integer[][]}
    def combinationSum(self, candidates, target):
        results = self.combinationSumRecursion(candidates, target)
        return self.uniqList(results)

    def combinationSumRecursion(self, candidates, target):
        results = []
        for item in candidates:
            if item == target:
                results.append([item])
        candidates = filter(lambda x: x<target, candidates)
        for item in candidates:
            tmp_results = self.combinationSumRecursion(candidates, target - item);
            results += [[item] + x for x in tmp_results]

        return results;

    def uniqList(self, results):
        uniq_results = []
        for item in results:
            item.sort()
            uniq_results.append(tuple(item))
        uniq_results = set(uniq_results)
        return [list(x) for x in uniq_results]

s = Solution()
candidates = [2,3,6,7]
target = 7
print 'candidates:',candidates, ' target:', target
print 'result:', s.combinationSum(candidates, target)
