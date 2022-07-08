class Solution {
public:
    void dfs(int curX, int curY, vector<vector<int>>& image, int m, int n, int orgColor, int newColor)
    {
        if(curX<0 || curY<0 || curX>=m || curY>=n) return;
        if(image[curX][curY] != orgColor) return;

        image[curX][curY] = newColor;
        dfs(curX-1, curY, image, m, n, orgColor, newColor);
        dfs(curX, curY-1, image, m, n, orgColor, newColor);
        dfs(curX+1, curY, image, m, n, orgColor, newColor);
        dfs(curX, curY+1, image, m, n, orgColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m, n;
        m = image.size();
        n = image[0].size();

        if(image[sr][sc] == newColor)
            return image;

        int orgColor = image[sr][sc];
        dfs(sr, sc, image, m, n, orgColor, newColor);

        return image;
    }
};
