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
    int helper(TreeNode *n, int &DIAM)
    {
        // returns height
        if(!n) return 0;

        int left = helper(n->left, DIAM), right = helper(n->right, DIAM);
        DIAM = max(DIAM, left + right); // diameter is #nodes - 1 in the longest path
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int DIAM = 0;
        helper(root, DIAM);
        return DIAM;
    }
};
