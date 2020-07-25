#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/

vector<int> target_range(vector<int>& nums, int target) {
    int a = -1;
    int b = -1;

    // low target
    int lo = 0;
    int hi = nums.size()-1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] == target && (mid == 0 || nums[mid-1] != target)) {
            a = mid;
            break;
        } else if(nums[mid] >= target) {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    // hi target
    lo = 0;
    hi = nums.size()-1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] == target && (mid == nums.size()-1 || nums[mid+1] != target)) {
            b = mid;
            break;
        } else if(nums[mid] <= target) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    return vector<int>{a, b};
}

int main() {
    vector<int> nums{1,2,3,4,4,4,4,5,6,7};
    vector<int> range = target_range(nums, 4);
    cout << range[0] << endl;
    cout << range[1] << endl;
    return 0;
}
