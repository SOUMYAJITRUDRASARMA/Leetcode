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
    struct Data
    {
        bool res;
        int ht;
        Data(bool r, int h){ res = r; ht = h; }
    };

    Data helper(TreeNode *n)
    {
        if(!n) return {true, 0};

        Data dl = helper(n->left), dr = helper(n->right);
        if(!dl.res || !dr.res) return {false, 0};
        return {abs(dl.ht - dr.ht) <= 1, 1 + max(dl.ht, dr.ht)};
    }

    bool isBalanced(TreeNode* root) {
        return helper(root).res;
    }
};
