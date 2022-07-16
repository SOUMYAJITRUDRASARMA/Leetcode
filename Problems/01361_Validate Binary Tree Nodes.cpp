class Solution {
public:
    bool helper(int cur, vector<int>& leftChild, vector<int>& rightChild, vector<int> &vis, unordered_set<int> &alphaNodes, int &numAlphaNodesRevisited)
    {
        if(vis[cur])
        {
            vis[cur]++;
            if(alphaNodes.find(cur) != alphaNodes.end())
            {
                if(vis[cur] == 2){ numAlphaNodesRevisited++; return true; }
                else return false;
            }
            else return false;
        }

        vis[cur]++;
        if(leftChild[cur] != -1 && !helper(leftChild[cur], leftChild, rightChild, vis, alphaNodes, numAlphaNodesRevisited)) return false;
        if(rightChild[cur] != -1 && !helper(rightChild[cur], leftChild, rightChild, vis, alphaNodes, numAlphaNodesRevisited)) return false;

        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> vis(n, 0);
        unordered_set<int> alphaNodes;

        int numAlphaNodesRevisited = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(!helper(i, leftChild, rightChild, vis, alphaNodes, numAlphaNodesRevisited)) return false;
                alphaNodes.insert(i); // pseudo-roots will have vis count max 2, others 1
            }
        }

        // case for disconnected tree
        // number of dfs = alphaNodes.size()
        // so if tree is connected, |number of dfs| = numAlphaNodesRevisited + 1
        return alphaNodes.size() == numAlphaNodesRevisited + 1;
    }
};
