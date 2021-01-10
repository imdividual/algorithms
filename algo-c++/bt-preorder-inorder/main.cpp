#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* bt_preorder_inorder(vector<int>& preorder, vector<int>& inorder,
                              unordered_map<int, int>& find, int &pre1, int in1, int in2) {
    if(pre1 >= preorder.size() || in1 > in2) return nullptr;
    int root = preorder[pre1];
    int index = find[root];
    ++pre1;
    TreeNode *left = bt_preorder_inorder(preorder, inorder, find, pre1, in1, index-1);
    TreeNode *right = bt_preorder_inorder(preorder, inorder, find, pre1, index+1, in2);
    return new TreeNode{root, left, right};
}

TreeNode* bt_preorder_inorder(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> find;
    for(int i = 0; i < inorder.size(); ++i) find[inorder[i]] = i;
    int pre1 = 0;
    return bt_preorder_inorder(preorder, inorder, find, pre1, 0, inorder.size()-1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
