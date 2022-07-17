/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *helper(int l, int r, vector<int> &v)
    {
        if(l > r) return nullptr;

        int m = (l + r) / 2;
        TreeNode *n = new TreeNode(v[m]);
        n->left = helper(l, m - 1, v);
        n->right = helper(m + 1, r, v);
        return n;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // a complete binary tree is height balanced
        // but this way needs, 1 ll traversals + 2 tree traversal -> 1. build bst structure from length, 2. preorder traversal and update value

        // rather dividing array into 2 halves and building the BST means 1 traversal each
        vector<int> v;
        while(head) v.push_back(head->val), head = head->next;

        return helper(0, v.size() - 1, v);
    }
};
