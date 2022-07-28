/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode *n, int k, unordered_set<int> &s)
    {
        if(!n) return false;

        if(helper(n->left, k, s)) return true;
        // if(n->val > k) return false;
        if(s.find(n->val) != s.end()) return true;
        s.insert(k - n->val);
        if(helper(n->right, k, s)) return true;

        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root, k, s);
    }
};
