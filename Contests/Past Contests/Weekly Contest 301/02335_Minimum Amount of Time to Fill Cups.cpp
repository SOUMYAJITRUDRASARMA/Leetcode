class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        return amount[0] + max(amount[1], amount[2] - amount[0]);
    }
};
