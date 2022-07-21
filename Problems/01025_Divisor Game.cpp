class Solution {
    vector<char> dp; // 'a' means not found, 'y' means win, 'n' means can't win
public:
    Solution(){ dp.resize(1001); fill(dp.begin(), dp.end(), 'a'); dp[0] = dp[1] = 'n'; }

    bool divisorGame(int n) {
        /* Better Solution
        // How it works ? Even -> win | Odd -> Lose
        // Explaination: Why is it optimal to choose 1 when you get even number? I think it can be proved as below. The key is whoever gets 1 looses. So if you got an even number and keep choosing 1 then your opponent will always get odd number (no matter what her/his choice of number is) and eventually that odd number will become 1. So for the player who gets even number, choosing 1 is bound to winning and thus optimal (might not be the fastest way to win though).
        // Now since Alice has first chance if she gets even number she will definitely win, otherwise bob will play optimally(giving odd number to Alice) and wins.
        // So eventually, we just have to check if the number is even or not.

        return n % 2 == 0; */

        // O(n^(3/2))
        if(dp[n] != 'a') return dp[n] == 'y';

        for(int factor=1;factor<sqrt(n);factor++)
            if(n % factor == 0 && !divisorGame(n - factor)){ dp[n] = 'y'; return true; } // alice wins if bob loses

        dp[n] = 'n';
        return false;
    }
};
