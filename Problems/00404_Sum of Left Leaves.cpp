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
    void helper(TreeNode *n, bool isLeft, int &sum)
    {
        if(isLeft && !n->left && !n->right) sum += n->val;
        if(n->left) helper(n->left, true, sum);
        if(n->right) helper(n->right, false, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, false, sum);
        return sum;
    }
};
