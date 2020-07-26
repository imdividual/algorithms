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

//  1 > 2 > 3 > 4 >

Node* linked_list_reverse_recursive(Node* head) {
    if(!head || !head->next) {
        return head;
    }
    Node *next = head->next;
    Node *nhead = linked_list_reverse_recursive(next);
    next->next = head;
    head->next = nullptr;
    return nhead;
}

int main() {
    Node *list1 = new Node{1,  new Node{2, new Node{3, nullptr}}};
    Node *list2 = linked_list_reverse_recursive(list1);
    while(list2) {
        cout << list2->val << endl;
        list2 = list2->next;
    }
    return 0;
}
