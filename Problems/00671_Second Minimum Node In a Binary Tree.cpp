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
    void helper(TreeNode *n, int min1, int &ans)
    {
        if(!n) return;

        if(n->val > min1){ if(ans == -1) ans = n->val; else ans = min(ans, n->val); return; }
        helper(n->left, min1, ans);
        helper(n->right, min1, ans);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;

        int min1 = root->val, ans = -1;
        helper(root, min1, ans);
        return ans;
    }
};
