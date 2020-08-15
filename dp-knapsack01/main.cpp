#include <bits/stdc++.h>
using namespace std;

void dp_knapsack01(vector<int> &sack, int W, vector<int> w, vector<int> v) {
    int dp[w.size()+1][W+1];
    for(int i = 0; i <= w.size(); ++i) {
        for(int j = 0; j <= W; ++j) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(j < w[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]]);
            }
        }
    }

    // backtrack to find items
    int i = w.size();
    int j = W;
    while(i > 0 && j > 0) {
        if(j >= w[i-1] && dp[i][j]-v[i-1] == dp[i-1][j-w[i-1]]) {
            sack.emplace_back(i);
            j -= w[i-1];
        }
        --i;
    }
}

int main() {
    vector<int> w{10, 20, 30};
    vector<int> v{60, 100, 120};
    vector<int> sack;
    dp_knapsack01(sack, 50, w, v);
    sort(sack.begin(), sack.end());
    for(auto i : sack) cout << i << endl;
    return 0;
}
