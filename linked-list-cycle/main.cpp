#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
};

bool linked_list_cycle_two(Node *head) {
    Node *p1 = head;
    Node *p2 = head;
    while(p2) {
        for(int i = 0; i < 2; ++i) {
            p2 = p2->next;
            if (!p2) return false;
            if (p1 == p2) return true;
        }
        p1 = p1->next;
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
