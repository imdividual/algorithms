#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

pair<int, int> bst_kth_smallest_pair(Node *root, int k) {
    if(!root) return make_pair(0, 0);
    pair<int, int> left = bst_kth_smallest_pair(root->left, k);
    pair<int, int> right = bst_kth_smallest_pair(root->right, k-left.first-1);
    int count = left.first + right.first + 1;
    int found = 0;
    if(left.first + 1 == k) found = root->key;
    else if(left.first >= k) found = left.second;
    else found = right.second;
    cout << root->key << " " << count << " " << found << endl;
    return make_pair(count, found);
}

int bst_kth_smallest(Node *root, int k) {
    return bst_kth_smallest_pair(root, k).second;
}

int main() {
    Node *root = new Node{ 4,
        new Node{ 2,
            new Node{ 1, nullptr, nullptr},
            new Node{ 3, nullptr, nullptr}
        },
        new Node { 6,
            new Node{ 5, nullptr, nullptr},
            new Node{ 7, nullptr, new Node{ 8, nullptr, nullptr}}
        }
    };
    cout << bst_kth_smallest(root, 8) << endl;
    return 0;
}
