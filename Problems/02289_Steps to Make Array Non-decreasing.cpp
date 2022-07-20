class Solution {
public:
    int totalSteps(vector<int>& nums) {
        // Notice that an element will be removed if and only if there exists a strictly greater element to the left of it in the array.
        // For each element, we need to find the number of rounds it will take for it to be removed. The answer is the maximum number of rounds for all elements. Build an array dp to hold this information where the answer is the maximum value of dp.
        // Use a stack of the indices. While processing element nums[i], remove from the stack all the indices of elements that are smaller than nums[i]. dp[i] should be set to the maximum of dp[i] + 1 and dp[removed index].

        stack<pair<int, int>> st;
        int cnt, res = 0;

        for(int i = nums.size() - 1;i >= 0;i--) {
            cnt = 0;

            while(!st.empty() && nums[i] > st.top().first) {
                cnt = max(cnt+1, st.top().second);
                st.pop();
            }

            res = max(res, cnt);
            st.push({nums[i], cnt});

        }

        return res;
    }
};
