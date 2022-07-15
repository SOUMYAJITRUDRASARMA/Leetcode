class Solution {
public:
    void floydWarshall(vector<vector<int>> &matrix){
	    // Code here
	    // APSP (in place - matrix)
	    // -1 if doesnot exist
	    int n = matrix.size();

	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(matrix[i][k] != -1 && matrix[k][j] != -1)
	                {
	                    if(matrix[i][j] == -1)
	                        matrix[i][j] = matrix[i][k] + matrix[k][j];
	                    else
	                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	                }
	            }
	        }
	    }
	}

	void countReachableCities(vector<vector<int>> &mat, vector<int> &cnt, int distanceThreshold)
	{
	    int n = mat.size();
	    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j] != -1 && mat[i][j] <= distanceThreshold)
                    cnt[i]++;
	}

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // -1 if edge doesnot exist
        vector<vector<int>> mat(n, vector<int>(n, -1));
        for(vector<int> &edge: edges) mat[edge[0]][edge[1]] = mat[edge[1]][edge[0]] = edge[2];
        for(int i=0;i<n;i++) mat[i][i] = 0;
        floydWarshall(mat);
        vector<int> cnt(n, -1); // because itself should be subtracted
        countReachableCities(mat, cnt, distanceThreshold);
        int ans = n - 1;
        for(int i=n-2;i>=0;i--) if(cnt[i] < cnt[ans]) ans = i;
        return ans;
    }
};
