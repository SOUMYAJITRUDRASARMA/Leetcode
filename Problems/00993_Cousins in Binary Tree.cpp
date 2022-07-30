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
    void helper(TreeNode *n, TreeNode *parent, int curHt, int x, int y, int &htX, int &htY, TreeNode *&parX, TreeNode *&parY)
    {
        if(!n) return;

        if(n->val == x) htX = curHt, parX = parent;
        else if(n->val == y) htY = curHt, parY = parent;

        if(htX != -1 && htY != -1) return;

        helper(n->left, n, curHt + 1, x, y, htX, htY, parX, parY);
        if(htX != -1 && htY != -1) return;

        helper(n->right, n, curHt + 1, x, y, htX, htY, parX, parY);
        if(htX != -1 && htY != -1) return;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int htX = -1, htY = -1;
        TreeNode *parX = nullptr, *parY = nullptr;
        helper(root, nullptr, 0, x, y, htX, htY, parX, parY);
        if(htX == -1 || htY == -1 || (!parX && !parY)) return false;
        return htX == htY && parX != parY;
    }
};
