class Solution {
public:
    struct Window
    {
        vector<bool> present;
        int cnt;
        Window(){ present.resize(256); fill(present.begin(), present.end(), false); cnt = 0; }
        bool canInsert(char ch){ return !present[ch]; }
        void insert(char ch){ present[ch] = true; cnt++; }
        void remove(char ch){ present[ch] = false; cnt--; }
        int size(){ return cnt; }
    };

    int lengthOfLongestSubstring(string s) {
        Window w;
        int ptr1 = 0, ptr2 = 0, n = s.size(), MAX = 0;
        while(ptr1 < n)
        {
            while(!w.canInsert(s[ptr1])) w.remove(s[ptr2++]);
            w.insert(s[ptr1++]);
            MAX = max(MAX, w.size());
        }

        return MAX;
    }
};
