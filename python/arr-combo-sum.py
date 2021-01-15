# https://leetcode.com/problems/combination-sum/
# https://leetcode.com/problems/combination-sum-ii/
# https://leetcode.com/problems/combination-sum-iii/

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
    
    def recurse2(self, candidates, target, los, lis, sm, i):
        if sm == target:
            los.append(lis[:])
        elif i < len(candidates):
            n = candidates[i]
            if sm + n <= target:
                lis.append(n)
                self.recurse2(candidates, target, los, lis, sm+n, i+1)
                lis.pop()
            while i+1 < len(candidates) and candidates[i] == candidates[i+1]:
                i += 1  
            self.recurse2(candidates, target, los, lis, sm, i+1)
      
    def combinationSum2(self, candidates, target):
        los = []
        lis = []
        candidates.sort()
        self.recurse2(candidates, target, los, lis, 0, 0)
        return los

    def recurse3(self, target, k, los, lis, sm, i):
        if sm == target and k == 3:
            los.append(lis[:])
        elif i <= 9 and k <= 3:
            n = i
            if sm + n <= target:
                lis.append(n)
                self.recurse3(candidates, target, k, los, lis, sm+n, i+1)
                lis.pop() 
            self.recurse2(candidates, target, los, lis, sm, i+1)
    
    def combinationSum3(self, k, n):
        los = []
        lis = []
        self.recurse3(candidates, target, k, los, lis, 0, 0)
        return los

        
test = Solution()

los = test.combinationSum([2,3,5], 8)
print(los)

los = test.combinationSum2([1,1,1,1,2,2,2,2,6], 8)
print(los)

los = test.combinationSum3(3, 9)
print(los)