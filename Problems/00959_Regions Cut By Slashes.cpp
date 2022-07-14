class DSU {
public:
    vector<int> parent;
    DSU(int N) {
        parent.resize(N);
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionDS(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        DSU dsu(4 * N * N);
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c) {
                int root = 4 * (r * N + c);
                char val = grid[r][c];
                if (val != '\\') {
                    dsu.unionDS(root + 0, root + 1);
                    dsu.unionDS(root + 2, root + 3);
                }
                if (val != '/') {
                    dsu.unionDS(root + 0, root + 2);
                    dsu.unionDS(root + 1, root + 3);
                }

                // north south
                if (r + 1 < N)
                    dsu.unionDS(root + 3, (root + 4 * N) + 0);
                if (r - 1 >= 0)
                    dsu.unionDS(root + 0, (root - 4 * N) + 3);
                // east west
                if (c + 1 < N)
                    dsu.unionDS(root + 2, (root + 4) + 1);
                if (c - 1 >= 0)
                    dsu.unionDS(root + 1, (root - 4) + 2);
            }

        int ans = 0;
        for (int x = 0; x < 4 * N * N; ++x) {
            if (dsu.find(x) == x)
                ans++;
        }

        return ans;
    }
};

/* class Solution {
public:
    struct Node
    {
        int i, j, k;
        Node(int i, int j, int k){ this->i = i, this->j = j, this->k = k; }
    };

    int regionsBySlashes(vector<string>& grid) {
        // a box is divided into 4 parts -->
        // \ 0 /
        // 1\ / 2
        //  / \
        // / 3 \
        // total nodes --> n * n * 4
        int n = grid.size();
        vector<vector<vector<vector<Node>>>> adj(n, vector<vector<vector<Node>>>(n, vector<vector<Node>>(4)));
        // adj[0 to n-1][0 to n-1][0 to 3]  -->  its neighbours
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++,c++)
            {
                if(grid[j] == '\\')
                {

                }
                else if(grid[c] == '/')
                {

                }
                else
                {
                    adj[i][j][
                }
            }
        }
    }
}; */
