class Solution:
    def recurse(self, candidates, target, los, lis, sm, i):
        if sm == target:
            los.append(lis[:])
        elif i < len(candidates):
            n = candidates[i]
            for j in range((target-sm)//n+1):
                for k in range(j):
                    lis.append(n)
                self.recurse(candidates, target, los, lis, sm+n*j, i+1)
                for k in range(j):
                    lis.pop()

    def combinationSum(self, candidates, target):
        los = []
        lis = []
        self.recurse(candidates, target, los, lis, 0, 0)
        return los
        
test = Solution()
los = test.combinationSum([2,3,5], 8)
print(los)