class Solution {
public:
    bool xorGame(vector<int>& nums) {
        // explaination in word file

        int x = 0;
        for (int e : nums) x ^= e;
        return x == 0 || nums.size() % 2 == 0;
    }
};
