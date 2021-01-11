# https://leetcode.com/problems/house-robber/

import math
import numpy as np

def rob(nums):
    if len(nums) == 0:
        return 0
    if len(nums) == 1:
        return nums[0]
    dp = np.zeros(len(nums))
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    for i in range(2, len(dp)):
        dp[i] = max(nums[i]+dp[i-2], dp[i-1])
    return int(dp[-1])

print(rob([0]))
