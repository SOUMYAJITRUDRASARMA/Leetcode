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
    TreeNode *helper(TreeNode *head)
    {
        // returns the tail after flattening, as head doesnot change
        TreeNode *tail = head, *hChild, *tChild, *tmp;
        while(head)
        {
            if(head->left)
            {
                hChild = head->left, tChild = helper(hChild);
                head->left = nullptr;
                tmp = head->right;
                head->right = hChild;
                tChild->right = tmp;

                head = tChild;
            }

            if(!head->right) return head;
            head = head->right;
        }

        return nullptr;
    }

    void flatten(TreeNode* root) {
        if(!root) helper(root);
    }
};
