#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

bool bst_validate_range(Node *root, long min, long max) {
    if(!root) return true;
    return
        min < root->val && root->val < max &&
        bst_validate_range(root->left, min, root->val) &&
        bst_validate_range(root->right, root->val, max);
}

bool bst_validate(Node *root) {
    return bst_validate_range(root, LONG_MIN, LONG_MAX);
}

int main() {
    return 0;
}
