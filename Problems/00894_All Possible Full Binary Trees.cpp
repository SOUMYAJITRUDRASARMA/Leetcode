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
    vector<vector<TreeNode *>> dp;

    Solution(){ dp.resize(21); dp[0].push_back(nullptr); dp[1].push_back(new TreeNode()); }

    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        if(!dp[n].empty()) return dp[n];

        for(int i=1;i<n;i+=2)
        {
            int j = n - 1 - i;
            for(TreeNode *left: allPossibleFBT(i))
                for(TreeNode *right: allPossibleFBT(j))
                    dp[n].push_back(new TreeNode(0, left, right));
        }

        return dp[n];
    }
};
