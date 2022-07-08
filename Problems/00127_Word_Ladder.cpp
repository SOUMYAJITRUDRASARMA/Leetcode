class Solution {
public:
    bool diffSingLetter(string &s1, string &s2)
    {
        int n = s1.size(), cnt = 0;
        for(int i=0;i<n;i++)
            if(s1[i] != s2[i])
                cnt++;

        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(string(beginWord));
        map<string, vector<string>> adj;
        map<string, bool> vis;
        string st, s;
        bool found = false;
        int n = wordList.size();
        for(string str: wordList)
            adj[str] = vector<string>();
        for(int i=0;i<n;i++)
        {
            st = wordList[i];
            if(st == endWord) found = true;

            vis[st] = false;
            for(int j=i+1;j<n;j++)
            {
                s = wordList[j];
                if(diffSingLetter(st, s))
                {
                    adj[st].push_back(s);
                    adj[s].push_back(st);
                }
            }
        }

        if(!found) return 0;

        // BFS
        queue<string> q1;
        queue<int> q2; // numWords

        q1.push(beginWord);
        q2.push(1);

        // for(string s: wordList){ cout<<s<<": "; for(string st: adj[s]) cout<<st<<" | "; cout<<endl; }

        while(!q1.empty())
        {
            st = q1.front(); q1.pop();
            n = q2.front(); q2.pop();
            // cout<<"st: "<<st<<" | n: "<<n<<endl;
            vis[st] = true;

            if(st == endWord) return n;

            for(string neighbour: adj[st])
            {
                if(!vis[neighbour])
                {
                    q1.push(neighbour);
                    q2.push(n + 1);
                }
            }
        }

        return 0;
    }
};
