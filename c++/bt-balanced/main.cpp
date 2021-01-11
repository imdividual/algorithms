#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

int bt_balanced_height(Node* root) {
    if(root == nullptr) return 0;
    int left = bt_balanced_height(root->left);
    int right = bt_balanced_height(root->right);
    if(left == -1 || right == -1 || abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}

bool bt_balanced(Node* root) {
    return bt_balanced_height(root) != -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
