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
    void helper(TreeNode *n, int &prev, int &curFreq, vector<int> &ans, int &maxFreq)
    {
        // Inordered is ascending order - simple as counting consecutive same range and finding and storing max
        if(!n) return;

        helper(n->left, prev, curFreq, ans, maxFreq);

        if(prev == n->val) curFreq++;
        else prev = n->val, curFreq = 1;

        if(curFreq == maxFreq) ans.push_back(n->val);
        else if(curFreq > maxFreq) maxFreq = curFreq, ans.clear(), ans.push_back(n->val);

        helper(n->right, prev, curFreq, ans, maxFreq);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxFreq = 0, prev = -1, curFreq = 0;
        helper(root, prev, curFreq, ans, maxFreq);
        return ans;
    }
};
