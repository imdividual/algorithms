#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game/
// greedy in O(n)
// dp is O(n^2)

// 1 2 0 4 2 0 0 0
// 0 0 1 0 3 2 1 0

bool jump_game(vector<int>& nums) {
    if(nums.size() <= 1)
        return true;
    int dist = 0;
    for(int i = nums.size()-2; i >= 0; --i) {
        ++dist;
        if(nums[i] >= dist) {
            dist = 0;
        }
    }
    return dist == 0;
}

int jump_game_min(vector<int>& nums) {
    int dp[nums.size()];
    for(int i = 0; i < nums.size(); ++i) dp[i] = INT_MAX;
    dp[0] = 0;
    // for(auto j : dp) cout << j << " "; cout << endl;
    for(int i = 0; i < nums.size(); ++i) {
        if(dp[i] == INT_MAX) continue;
        int jump = nums[i];
        for(int j = 1; j <= jump; ++j) {
            if(i+j < nums.size())
                dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    return dp[nums.size()-1];
}

int main() {
    vector<int> nums{2,3,1,1,4};
    cout << jump_game(nums) << endl;
    cout << jump_game_min(nums) << endl;
    return 0;
}
