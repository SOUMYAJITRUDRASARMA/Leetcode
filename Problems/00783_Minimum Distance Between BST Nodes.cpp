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
    void helper(TreeNode *n, int &MIN, int &prev)
    {
        if(!n) return;

        helper(n->left, MIN, prev);
        MIN = min(MIN, n->val - prev);
        prev = n->val;
        helper(n->right, MIN, prev);
    }

    int minDiffInBST(TreeNode* root) {
        int MIN = INT_MAX, prev = -(INT_MAX / 2);
        helper(root, MIN, prev);
        return MIN;
    }
};
