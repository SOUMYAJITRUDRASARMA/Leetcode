class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), cnt = 0; // matrix[i][j] becomes max len of square formed with right bottom point at posn (i, j)
        for(int i=0;i<m;i++) cnt += matrix[i][0];
        for(int i=1;i<n;i++) cnt += matrix[0][i]; // why 1 ? not to double count matrix[0][0]

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                cnt += matrix[i][j] = (matrix[i][j])? (1 + min( {matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j]} )): 0;

        return cnt;
    }
};
