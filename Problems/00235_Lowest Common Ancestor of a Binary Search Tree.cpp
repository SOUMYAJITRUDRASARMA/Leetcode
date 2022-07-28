/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool searchHelper(TreeNode *n, TreeNode *s, stack<TreeNode *> &st)
    {
        if(!n) return false;

        st.push(s);

        if(n == s) return true;
        else if(s->val < n->val) return searchHelper(n->left, s, st);
        else return searchHelper(n->right, s, st);

        st.pop();

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* stack<TreeNode *> s1, s2;
        if(!searchHelper(root, p, s1)) return nullptr;
        if(!searchHelper(root, q, s2)) return nullptr; */

        if(p == root || q == root) return root;

        if(((long long)(p->val - root->val)) * (q->val - root->val) > 0) return lowestCommonAncestor((p->val < root->val)? root->left: root->right ,p, q);
        else return root;
    }
};
