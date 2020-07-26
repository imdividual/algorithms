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

int main() {
    vector<int> nums{1, 2, 0, 4, 2, 0, 0, 0};
    cout << jump_game(nums) << endl;
    return 0;
}
