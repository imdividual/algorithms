#include <bits/stdc++.h>
using namespace std;

// longest common subsequence

int dp_lcs(string a, string b) {
    int dp[a.length()+1][b.length()+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= a.length(); ++i) {
        for(int j = 1; j <= b.length(); ++j) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[a.length()][b.length()];
}

int main() {
    cout << dp_lcs("abcrrr", "atttbtttc") << endl;
    cout << dp_lcs("b", "a") << endl;
    return 0;
}
