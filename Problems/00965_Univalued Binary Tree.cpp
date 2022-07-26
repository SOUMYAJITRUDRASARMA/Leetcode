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
    bool helper(TreeNode *n, int val)
    {
        if(!n) return true;

        if(n->val != val) return false;

        if(!helper(n->left, val)) return false;
        if(!helper(n->right, val)) return false;

        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;

        return helper(root, root->val);
    }
};
