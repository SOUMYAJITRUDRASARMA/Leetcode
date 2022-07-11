// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

/* C++ Binary Lifting
    1. Make a matrix of size n * floor(log2(n))+1
    2. n rows for n nodes
    3. floor(log2(n))+1 columns for storing (1<<col_no)th ancestor of that node
    4. We will store 2^0, 2^1, 2^2, 2^3th ancestor for each node
    5. We will get 2^i th ancestor from 2^(i-1)th ancestor
    6. For finding kth ancestor we will use that table and finding ancestor for every bit of k which is 1 */


class TreeAncestor {

    vector<vector<int>>look;

public:
    TreeAncestor(int n, vector<int>& parent) {
        // Binary Lifting allows O(log(n)) search instead of O(n)
        int si = floor(log2(n))+1;

        look.resize(n, vector<int>(si));
        for(int i=0;i<n;i++){
            look[i][0] = parent[i];
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<si;j++){
                if(look[i][j-1]!=-1){
                    look[i][j] = look[look[i][j-1]][j-1];
                }else{
                    look[i][j]=-1;
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int cur = node;
        for(int b=0;b<32&&cur!=-1;b++){
            if(k&(1<<b)){
                cur = look[cur][b];
            }
        }
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
