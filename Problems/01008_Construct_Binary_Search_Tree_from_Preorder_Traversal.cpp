// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void insertBst(TreeNode *root, TreeNode *node)
    {
        while(root->left!=nullptr || root->right!=nullptr)
        {
            if(node->val > root->val)
            {
                if(root->right==nullptr) break;
                else root = root->right;
            }
            else
            {
                if(root->left==nullptr) break;
                else root = root->left;
            }
        }

        if(node->val > root->val) root->right = node;
        else root->left = node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = nullptr;
        int n = preorder.size();

        if(n == 0)
            return root;

        root = new TreeNode(preorder[0]);
        for(int i=1;i<n;i++)
        {
            // as pre-order , first nodes values are given, higesht nodes of a not yet built subtree are given first, so insert in order ...
            insertBst(root, new TreeNode(preorder[i]));
        }

        return root;
    }
};
