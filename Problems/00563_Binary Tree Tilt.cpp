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
    int helperSum(TreeNode *n, int &sum)
    {
        if(!n) return 0;

        int leftSum = helperSum(n->left, sum), rightSum = helperSum(n->right, sum);
        sum += abs(leftSum - rightSum);
        return n->val + leftSum + rightSum;
    }

    int findTilt(TreeNode* root) {
        int sum = 0;
        helperSum(root, sum);
        return sum;
    }
};
