#include <bits/stdc++.h>
using namespace std;

int dp_knapsack01(vector<int> w, vector<int> v, int W) {
    int dp[w.size()+1][W+1];
    for(int i = 0; i <= w.size(); ++i) {
        for(int j = 0; j <= W; ++j) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(j < w[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);
            }
        }
    }
    return dp[w.size()][W];
}

int main() {
    vector<int> w{10, 20, 30};
    vector<int> v{60, 100, 120};
    cout << dp_knapsack01(w, v, 50) << endl;
    return 0;
}
