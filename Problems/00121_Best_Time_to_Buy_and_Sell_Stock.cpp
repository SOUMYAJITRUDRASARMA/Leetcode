// Like Kadane's algorithm


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN = prices[0], n = prices.size(), maxProfit = 0;
        for(int i=1;i<n;i++)
        {
            maxProfit = max(maxProfit, prices[i] - MIN);
            MIN = min(MIN, prices[i]);
        }

        return maxProfit;
    }
};
