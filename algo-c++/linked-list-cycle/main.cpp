#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
};

bool linked_list_cycle_floyd(Node *head) {
    if(!head) return false;
    Node *slow = head;
    Node *fast = head;
    while(slow->next && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

bool linked_list_cycle_map(Node *head) {
    unordered_set<Node*> nodes;
    Node *cur = head;
    while(cur) {
        if(nodes.count(cur)) return true;
        nodes.insert(cur);
        cur = cur->next;
    }
    return false;
}

int main() {
    return 0;
}
