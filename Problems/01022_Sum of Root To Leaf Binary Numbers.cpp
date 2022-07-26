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
    int helper(TreeNode *n, int num)
    {
        if(!n) return 0;

        num = num * 2 + n->val;
        if(!n->left && !n->right) return num;
        return helper(n->left, num) + helper(n->right, num);
    }

    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};
