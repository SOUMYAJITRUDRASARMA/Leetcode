// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways)
// to roll the dice so the sum of the face-up numbers equals target.
// Since the answer may be too large, return it modulo 10^9 + 7


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
// #define MOD 1000000007

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const long long MOD = 1000000007;
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));
        dp[0][0] = 1;

        for(int dice=1;dice<=n;dice++)
        {
            for(int tar=1;tar<=target;tar++)
            {
                for(int i=1;i<=k;i++)
                {
                    if(tar - i < 0)
                        break;
                    dp[dice][tar] = (dp[dice][tar] + dp[dice-1][tar-i]) % MOD;
                }
            }
        }

        // for(vector<long long> &v: dp){ for(long long e: v) cout<<e<<" "; cout<<endl; }

        return (int)dp[n][target];
    }
};

int main()
{
    int t;
	cin>>t;
	while(t--)
	{

	}

    return 0;
}
