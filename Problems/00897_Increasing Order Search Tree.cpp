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
    void helper(TreeNode *n, vector<TreeNode *> &v)
    {
        // inorder
        if(!n) return;

        helper(n->left, v);
        v.push_back(n);
        helper(n->right, v);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;

        vector<TreeNode *> v;
        helper(root, v);
        int n = v.size();
        for(int i=0;i<n-1;i++) v[i]->left = nullptr, v[i]->right = v[i + 1];
        v.back()->left = v.back()->right = nullptr;

        return v.front();
    }
};
