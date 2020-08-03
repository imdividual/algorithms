#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* sortedArrayToBST(vector<int>& nums, int a, int b) {
    if(a > b) return nullptr;
    if(a == b) return new TreeNode{nums[a], nullptr, nullptr};
    int mid = a + (b - a) / 2;
    TreeNode *left = sortedArrayToBST(nums, a, mid-1);
    TreeNode *right = sortedArrayToBST(nums, mid+1, b);
    return new TreeNode {nums[mid], left, right};
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size()-1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
