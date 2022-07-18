/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *helper(Node *n, unordered_map<Node *, Node *> &m)
    {
        if(m.find(n) != m.end()) return m[n];

        m[n] = new Node(n->val);
        m[n]->next = helper(n->next, m);
        m[n]->random = helper(n->random, m);
        return m[n];
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> m;
        m[nullptr] = nullptr;
        return helper(head, m);
    }
};
