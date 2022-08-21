class Solution {
public:
    int gcd(int a, int b)
    {
        if(!b) return a;
        else return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        /* int ans = nums.front();
        for(int e: nums) ans = (ans >= e)? gcd(ans, e): gcd(e, ans);
        return ans; */

        int MIN = INT_MAX, MAX = INT_MIN;
        for(int e: nums) MIN = min(MIN, e), MAX = max(MAX, e);
        return gcd(MAX, MIN);
    }
};
