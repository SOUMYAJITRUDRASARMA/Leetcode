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

        helper(n->left, v);
        if(!n->left && !n->right) v.push_back(n->val);
        helper(n->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        helper(root1, v1);
        helper(root2, v2);

        return v1 == v2;
    }
};
