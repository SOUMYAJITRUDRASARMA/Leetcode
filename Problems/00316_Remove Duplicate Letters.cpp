class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.size() <= 1) return s;

        vector<int> freq(26, 0);
        for(char ch: s) freq[ch - 'a']++;

        string ans;
        char index = 'a';
        while(!freq[index - 'a']) index++;
        vector<bool> present(26, false);
        for(char ch: s)
        {
            if(!present[ch - 'a'])
            {
                while(!ans.empty() && ch < ans.back() && freq[ans.back() - 'a']) present[ans.back() - 'a'] = false, ans.pop_back();

                ans.push_back(ch);
                present[ch - 'a'] = true;
            }

            freq[ch - 'a']--;

            /* freq[ch - 'a']--;
            if(!present[ch - 'a'])
            {

                 if(!freq[ch - 'a'] || ch == index)
                {
                    ans.push_back(ch);
                    index++;
                    while(index < 'z' && !freq[index - 'a']) index++;
                }
            } */
        }

        return ans;
    }
};
