#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums {-3, -2, -1, 0, 1, 2, 3};
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> combos;
    for(int i = 0; i < nums.size(); ++i) {
        int p1 = i+1;
        int p2 = nums.size()-1;
        while(p1 < p2) {
            int sum = nums[i] + nums[p1] + nums[p2];
            if(sum == 0) {
                vector<int> combo {nums[i], nums[p1], nums[p2]};
                combos.emplace_back(combo);
                while(p1+1 < nums.size() && nums[p1] == nums[p1+1]) ++p1;
            }
            if(sum > 0) --p2; else ++p1;
        }
        while(i+1 < nums.size() && nums[i] == nums[i+1]) ++i;
    }

}

