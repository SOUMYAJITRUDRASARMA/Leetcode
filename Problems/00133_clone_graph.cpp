#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    map<int, Node *> m;
public:

    Node* cloneGraph(Node* node)
    {
        // dfs
        if(node == nullptr)
            return node;

        if(m.find(node->val) == m.end())
            m[node->val] = new Node(node->val);

        for(Node *neighbour: node->neighbors)
        {
            if(m.find(neighbour->val) == m.end()) // not visited , hence not cloned nodes
                cloneGraph(neighbour);
            m[node->val]->neighbors.push_back(m[neighbour->val]); // adding edges on end recursion after nodes have been created
        }

        return m[node->val];
    }
};
