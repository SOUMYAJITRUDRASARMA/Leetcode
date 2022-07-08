# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int curPos = 0, minLen = INT_MAX;
        for(string &st: strs) minLen = min(minLen, (int)st.size());

        char ch;
        bool allSame;
        while(curPos < minLen)
        {
            ch = strs[0][curPos], allSame = true;
            for(string &st: strs) if(st[curPos] != ch){ allSame = false; break; }
            if(!allSame) break;
            curPos++;
        }

        return string(strs[0].begin(), strs[0].begin() + curPos);
    }
};
