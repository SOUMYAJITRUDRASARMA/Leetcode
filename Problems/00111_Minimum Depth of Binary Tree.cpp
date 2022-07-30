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
    void helper(TreeNode *n, int curDepth, int &MIN)
    {
        if(!n->left && !n->right){ MIN = min(MIN, curDepth); return; }
        if(n->left) helper(n->left, curDepth + 1, MIN);
        if(n->right) helper(n->right, curDepth + 1, MIN);
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;

        int MIN = INT_MAX;
        helper(root, 1, MIN);
        return MIN;
    }
};
