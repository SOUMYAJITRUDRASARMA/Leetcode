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
    void helper(TreeNode *n, vector<int> &v)
    {
        if(!n) return;

        v.push_back(n->val);
        helper(n->left, v);
        helper(n->right, v);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return v;
    }
};