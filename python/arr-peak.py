# https://leetcode.com/problems/find-peak-element/

class Solution:
    def findPeakElement(self, nums):
        N = len(nums)
        lo = 0
        hi = N-1
        while lo <= hi:
            mid = lo + (hi-lo)//2
            if mid > 0 and nums[mid-1] >= nums[mid]:
                hi = mid-1
            elif mid < N-1 and nums[mid+1] >= nums[mid]:
                lo = mid+1
            else:
                return mid

test = Solution()
i = test.findPeakElement([1,2,1,3,5,6,4])
print(i)
        