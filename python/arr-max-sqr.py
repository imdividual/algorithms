class Solution:
    def maximalSquare(self, matrix):
        M = len(matrix)
        N = len(matrix[0]) 
        dp = [[0 for i in range(N+1)] for i in range(M+1)]
        for i in range(1, M+1):
            for j in range(1, N+1):
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]
                if matrix[i-1][j-1] == "1": dp[i][j] += 1
        
        print('\n'.join([' '.join([str(i) for i in r]) for r in dp]))

        sqr = [[0 for i in range(N+1)] for i in range(M+1)]
        for i in range(1, M+1):
            for j in range(1, N+1):
                for l in range(min(i, j)+1):
                    sq = dp[i][j]-dp[i-l][j]-dp[i][j-l]+dp[i-l][j-l]
                    if sq == l*l:
                        sqr[i][j] = max(sqr[i][j], sq)
                    else:
                        sqr[i][j] = max(sqr[i][j], sqr[i-1][j], sqr[i][j-1])

        print()
        print('\n'.join([' '.join([str(i) for i in r]) for r in sqr]))s

        return sqr[M][N]

test = Solution()
matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
print(test.maximalSquare(matrix))
print()
matrix = [["0","1"],["1","0"]]
print(test.maximalSquare(matrix))
