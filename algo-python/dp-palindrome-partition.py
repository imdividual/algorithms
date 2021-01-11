# https://leetcode.com/problems/palindrome-partitioning/

import numpy as np

class Solution:

    def palindrome(self, s):
        N = len(s)
        dp = [[None for j in range(N)] for i in range(N)]
        for k in range(N):
            for i in range(N):
                if i + k < N:
                    if k == 0:
                        dp[i][i+k] = True
                    elif k == 1:
                        dp[i][i+k] = s[i] == s[i+1]
                    else:
                        dp[i][i+k] = (s[i] == s[i+k]) and dp[i+1][i+k-1]
        for i in range(N):
            print(dp[i])
        return dp

    def recurse(self, parts, part, s, dp, i):
        N = len(s)
        if i == N:
            parts.append(part[:])
        else:
            for j in range(i, N):
                if dp[i][j]:
                    part.append(s[i:j+1])
                    self.recurse(parts, part, s, dp, j+1)
                    part.pop()

    def partition(self, s: str):
        N = len(s)
        dp = self.palindrome(s)
        parts = []
        part = []
        self.recurse(parts, part, s, dp, 0)
        print(parts)
        return parts

test = Solution()
test.partition("abbab")