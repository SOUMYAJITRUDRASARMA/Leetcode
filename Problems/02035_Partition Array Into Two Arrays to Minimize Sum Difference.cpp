class Solution {
public:
    /* void helper(int curSum, int pos, int cnt, int totSum, int n, vector<int> &nums, int &MIN)
    {
        if(cnt == n)
        {
            MIN = min(MIN, abs(2 * curSum - totSum));
            return;
        }

        if(pos == 2 * n) return;

        helper(curSum, pos + 1, cnt, totSum, n, nums, MIN);
        helper(curSum + nums[pos], pos + 1, cnt + 1, totSum, n, nums, MIN);
    } */

    void helper(int curSum, int pos, int cnt, int n, vector<int> &nums, vector<vector<int>> &a)
    {
        if(pos == n)
        {
            a[cnt].push_back(curSum);
            return;
        }

        helper(curSum, pos + 1, cnt, n, nums, a);
        helper(curSum + nums[pos], pos + 1, cnt + 1, n, nums, a);
    }

    int minimumDifference(vector<int>& nums) {
        int MIN = INT_MAX, sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size() / 2;
        // helper(0, 0, 0, sum, n, nums, MIN);

        vector<vector<int>> a(n + 1), b(n + 1);
        helper(0, 0, 0, n, nums, a);
        helper(0, n, 0, 2 * n, nums, b);

        for(vector<int> &v: a) sort(v.begin(), v.end());

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<b[i].size();j++)
            {
                auto it = lower_bound(a[n - i].begin(), a[n - i].end(), sum / 2 - b[i][j]);
                if(it != a[n - i].end()) MIN = min(MIN, abs(sum - 2 * (b[i][j] + *it)));
                it--;
                if(it >= a[n - i].begin()) MIN = min(MIN, abs(sum - 2 * (b[i][j] + *it)));
            }
        }

        return MIN;
    }
};
