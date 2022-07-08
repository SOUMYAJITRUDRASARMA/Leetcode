// https://leetcode.com/problems/search-a-2d-matrix/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low, high, mid, row;
        bool found;

        low = 0, high = m-1, found = false;
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            if(target < matrix[mid][0]) high = mid - 1;
            else if(target > matrix[mid][n-1]) low = mid + 1;
            else{ found = true; break; }
        }
        if(!found) return false;
        row = mid;

        low = 0, high = n-1, found = false;
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            if(target < matrix[row][mid]) high = mid - 1;
            else if(target > matrix[row][mid]) low = mid + 1;
            else{ found = true; break; }
        }

        return found;
    }
};
