#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* bt_preorder_inorder(
        vector<int>& preorder, vector<int>& inorder,
        unordered_map<int, int> &preindex, unordered_map<int, int> &inindex,
        int p1, int p2, int i1, int i2) {

    if(p1 == p2) return new TreeNode {preorder[p1], nullptr, nullptr};

    int val = preorder[p1];
    int mid = inindex[val];
    int end = mid != i1 ? preindex[inorder[mid-1]] : p1;

    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    int pl1 = p1+1;
    int pl2 = end;
    int pr1 = end+1;
    int pr2 = p2;
    int il1 = i1;
    int il2 = mid-1;
    int ir1 = mid+1;
    int ir2 = i2;

    if(mid != i1) {
        left = bt_preorder_inorder(preorder, inorder, preindex, inindex, pl1, pl2, il1, il2);
    }

    if(mid != i2) {
        right = bt_preorder_inorder(preorder, inorder, preindex, inindex, pr1, pr2, ir1, ir2);
    }

    return new TreeNode{val, left, right};
}

TreeNode* bt_preorder_inorder(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty()) return nullptr;
    unordered_map<int, int> preindex, inindex;
    for(int i = 0; i < preorder.size(); ++i) {
        preindex[preorder[i]] = i;
        inindex[inorder[i]] = i;
    }
    return bt_preorder_inorder(
            preorder, inorder,
            preindex, inindex,
            0, preorder.size()-1,
            0, inorder.size()-1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
