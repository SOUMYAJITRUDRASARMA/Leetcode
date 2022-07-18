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
    /* bool helper(ListNode* head, ListNode *orgHead, TreeNode* root)
    {
        if(!head && !root) return true;
        if(head && !root) return false;
        if(!head && root) return true;

        if(head->val != root->val)
            return helper(orgHead, orgHead, root->left) ||
                   helper(orgHead, orgHead, root->right);
        else
            return helper(head->next, orgHead, root->left) ||
                   helper(head->next, orgHead, root->right) ||
                   helper(orgHead, orgHead, root->left) ||
                   helper(orgHead, orgHead, root->right);
    } */

    bool solve(ListNode* head,TreeNode* root)
    {
        if(head==nullptr) return true;
        if(root==nullptr) return false;
        if(head->val!=root->val) return false;
        return solve(head->next,root->left) || solve(head->next,root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        // return helper(head, head, root);

        if(head==nullptr) return true;
        if(root==nullptr) return false;
        return solve(head,root) or isSubPath(head,root->left) or isSubPath(head,root->right);
    }
};
