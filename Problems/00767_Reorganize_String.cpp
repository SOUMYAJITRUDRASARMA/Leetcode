// https://www.youtube.com/watch?v=zaM_GLLvysw


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for(char ch: s) m[ch]++;
        // deque<char> dq;
        priority_queue<pair<int, char>> pq;
        // for(pair<char, int> p: m) while(p.first--) dq.push_back(p.first);
        for(pair<char, int> p: m) pq.push(make_pair(p.second, p.first));

        string ans, emptyString;
        pair<int, char> p1, p2;
        while(pq.size() > 1)
        {
            // use the most frequently occuring characters first
            p1 = pq.top(); pq.pop();
            p2 = pq.top(); pq.pop();

            if(ans.empty() || ans.back() != p1.second)
            {
                ans.push_back(p1.second);
                ans.push_back(p2.second);
            }
            else
            {
                ans.push_back(p2.second);
                ans.push_back(p1.second);
            }

            p1.first--;
            p2.first--;

            if(p1.first) pq.push(p1);
            if(p2.first) pq.push(p2);
        }

        if(!pq.empty())
        {
            p1 = pq.top(); pq.pop();
            if(p1.first > 1) return emptyString;

            ans.push_back(p1.second);
        }

        return ans;

        /*char ch1, ch2;
        while(dq.size > 1)
        {
            ch1 = dq.front(); dp.pop_front();
            ch2 = dq.back(); dp.pop_back());

            if(ch1 == ch2) return emptyString;

            ans.push_back(ch1);
            ans.push_back(ch2);
        }

        return ans;*/
    }
};
