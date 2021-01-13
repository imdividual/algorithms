# https://leetcode.com/problems/largest-number/

import re
from functools import cmp_to_key

class Solution:
    def largestNumberSort(self, x, y):
        c1 = int(x+y)
        c2 = int(y+x)
        return c1-c2

    def largestNumber(self, nums):
        for i in range(len(nums)):
            nums[i] = str(nums[i])
        nums = sorted(nums, key=cmp_to_key(self.largestNumberSort), reverse=True)
        largest = ""
        for i in range(len(nums)):
            largest += nums[i]
        
        if int(largest) == 0:
            return "0"

        return largest        

test = Solution()
l = test.largestNumber([3,30,34,5,9])
print(l)
        