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
    void pushNum(string &curPath, int n)
    {
        string nStr = to_string(n);
        if(!curPath.empty()) curPath.push_back('-'), curPath.push_back('>');

        for(char ch: nStr) curPath.push_back(ch);
    }

    void popNum(string &curPath)
    {
        while(!curPath.empty() && curPath.back() != '>') curPath.pop_back();
        if(!curPath.empty()) curPath.pop_back(), curPath.pop_back();
    }

    void helper(TreeNode *n, string &curPath, vector<string> &ans)
    {
        if(!n) return;

        pushNum(curPath, n->val);

        helper(n->left, curPath, ans);
        if(!n->left && !n->right) ans.push_back(curPath);
        helper(n->right, curPath, ans);

        popNum(curPath);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curPath;
        helper(root, curPath, ans);
        return ans;
    }
};
