/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node* n, vector<int> &v)
    {
        if(!n) return;

        for(Node *child: n->children)
            helper(child, v);

        v.push_back(n->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> v;
        helper(root, v);
        return v;
    }
};
