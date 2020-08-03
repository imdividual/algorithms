#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

Node* array_sorted_to_balanced_bst(vector<int> &nums, int a, int b) {
    if (a > b) return nullptr;
    if (a == b) return new Node{nums[a], nullptr, nullptr};
    int mid = a + (b - a) / 2;
    Node *left = array_sorted_to_balanced_bst(nums, a, mid - 1);
    Node *right = array_sorted_to_balanced_bst(nums, mid + 1, b);
    return new Node{nums[mid], left, right};
}

void bst_to_array(Node *root, vector<int> &arr) {
    if(root) {
        bst_to_array(root->left, arr);
        arr.emplace_back(root->val);
        bst_to_array(root->right, arr);
    }
}

Node *bst_balance(Node *root) {
    vector<int> arr;
    bst_to_array(root, arr);
    return array_sorted_to_balanced_bst(arr, 0, arr.size() - 1);
}

int main() {
    return 0;
}
