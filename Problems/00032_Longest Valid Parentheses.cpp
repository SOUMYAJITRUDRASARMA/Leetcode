class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, MAX = 0;
        for(char ch: s)
        {
            if(ch == '(') left++;
            else right++;

            if(left == right) MAX = max(MAX, 2 * right);
            else if(right > left) left = right = 0;
        }

        left = right = 0;
        char ch;
        for(int i=s.size()-1;i>=0;i--)
        {
            ch = s[i];

            if(ch == '(') left++;
            else right++;

            if(left == right) MAX = max(MAX, 2 * left);
            else if(right < left) left = right = 0;
        }

        return MAX;
    }
};
