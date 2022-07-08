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
    TreeNode *delHelper(TreeNode *n)
    {
        if(!n->left && !n->right){ delete n; return nullptr; }
        else if(n->left && !n->right){ TreeNode *nd =  n->left; delete n; return nd; }
        else if(!n->left && n->right){ TreeNode *nd =  n->right; delete n; return nd; }
        else
        {
            // Finding inorder predecessor
            if(!n->left->right)
            {
                TreeNode *nd =  n->left; nd->right = n->right; delete n; return nd;
            }
            else
            {
                TreeNode *nOrg = n;
                n = n->left;
                while(n->right->right) n = n->right;
                nOrg->val = n->right->val;
                n->right = delHelper(n->right);

                return nOrg;
            }
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val == key){ root = delHelper(root); return root; }
        TreeNode *r = root;
        while(r != nullptr)
        {
            if((r->left && r->left->val == key) || (r->right && r->right->val == key)) break;
            else if(key > r->val) r = r->right;
            else r = r->left;
        }

        if(r == nullptr) return root;

        if(r->left && r->left->val == key) r->left = delHelper(r->left);
        else r->right = delHelper(r->right);

        return root;
    }
};
