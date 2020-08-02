#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths/

int unique_paths(int m, int n) {
    int dp[m+1][n+1];
    memset(dp, 0 , sizeof(dp));
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == 1 && j == 1) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

int main() {
    cout << unique_paths(7, 3);
}
