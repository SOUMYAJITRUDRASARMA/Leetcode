// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        for(int e: arr)
            m[e]++;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(pair<int,int> p: m)
            pq.push(p.second);

        int e;
        while(!pq.empty())
        {
            e = pq.top();
            if(k < e)
                return pq.size();
            else if(k == e)
                return pq.size() - 1;
            else
            {
                pq.pop();
                k -= e;
            }
        }

        return 0;
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
