class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // ants changing direction is equivalent to ants continuing their own path

        int MAX = 0;
        for(int e: left) MAX = max(MAX, e);
        for(int e: right) MAX = max(MAX, n - e);

        return MAX;
    }
};
