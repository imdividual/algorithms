#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/

bool partition(vector<int>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) sum += nums[i];
    if(sum % 2 != 0) return false;
    sum /= 2;

    bool dp[nums.size()+1][sum+1];
    for(int i = 0; i <= nums.size(); ++i) {
        for(int j = 0; j <= sum; ++j) {
            if(i == 0) {
                dp[i][j] = false;
            } else if(j == 0) {
                dp[i][j] = true;
            } else if(j >= nums[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[nums.size()][sum];
}

int main() {
    vector<int> n1 {1, 5, 11, 5};
    vector<int> n2 {1, 2, 3, 5};
    cout << partition(n1) << endl;
    cout << partition(n2) << endl;
    return 0;
}
