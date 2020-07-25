#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
};

//  1 > 2 > 3 > 4 >

Node* linked_list_reverse(Node* head) {
    Node *cur = head;
    Node *prev = nullptr;

    while(cur) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

int main() {
    Node *list1 = new Node{1,  new Node{2, new Node{3, nullptr}}};
    Node *list2 = linked_list_reverse(list1);
    while(list2) {
        cout << list2->val << endl;
        list2 = list2->next;
    }
    return 0;
}
