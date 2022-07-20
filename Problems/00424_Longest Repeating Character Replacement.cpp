class Solution {
public:
    int characterReplacement(string s, int k) {
        // O(n)
        //keep track of most frequent character in the window. if all else is k changes,
        //then that's the length
        vector<int> freq(26,0);
        int start = 0;
        int end = 0;
        int longest = 0;
        int locMax = 0;
        for(;end < s.length(); end++){
            freq[s[end]-'A']++;
            locMax = std::max(freq[s[end]-'A'], locMax);
            while(end - start + 1 - locMax > k){
                freq[s[start]-'A']--;
                start++;
                // locMax = 0;
                // for(int i: freq) locMax = std::max(locMax, i);

            }
            longest = max(longest, end - start + 1);
        }

        return longest;




        /* Easier - O(26 * n)
        int ans = 0;
        int n = s.size();
        for(char ch = 'A';ch<='Z';ch++)
        {
            int start = 0,end = 0,other = 0;
            while(end<n)
            {
                if(s[end]!=ch)
                    other++;
                while(other>k)
                {
                    if(s[start]!=ch)other--;
                    start++;
                }
                ans = max(ans,end-start+1);
                end++;
            }
        }
        return ans; */
    }
};
