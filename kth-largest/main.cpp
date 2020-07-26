#include <bits/stdc++.h>
using namespace std;

// find kth largest element in array

int kth_largest(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());
    for(int i = 0; i < k-1; ++i) {
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }
    return nums.front();
}

int main() {
    vector<int> nums{1,8,3,2,6,5,7,4};
    cout << kth_largest(nums, 4) << endl;
    return 0;
}
