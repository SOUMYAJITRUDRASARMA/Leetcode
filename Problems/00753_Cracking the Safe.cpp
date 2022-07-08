class Solution {
public:
    int index(int num, int k)
    {
        int sum = 0, base = 1;
        while(num) sum += (num % 10) * base, num /= 10, base *= k;
        return sum;
    }

    int numOfIndex(int ind, int k)
    {
        int sum = 0, base = 1;
        while(ind) sum += (ind % k) * base, ind /= k, base *= 10;
        return sum;
    }

    int removeFirstDigit(int code, int len)
    {
        int base = pow(10, len - 1);
        return code % base;
    }

    vector<int> heirholzer(vector<vector<int>> &adj, int n)
    {
        if(n == 0) return vector<int>();

        stack<int> curPath;
        curPath.push(0);
        vector<int> circuit;

        int curVertex, nextVertex;
        while(!curPath.empty())
        {
            curVertex = curPath.top();
            if(!adj[curVertex].empty())
            {
                nextVertex = adj[curVertex].back();
                adj[curVertex].pop_back();
                curPath.push(nextVertex);
            }
            else
            {
                circuit.push_back(curVertex);
                curPath.pop();
            }
        }

        reverse(circuit.begin(), circuit.end());
        return circuit;
    }

    string crackSafe(int n, int k) {
        // De - Bruijn Sequence
        // length 'n' means 'n-1' digits in nodes of graph
        // k ^ n-1 nodes
        if(n == 1)
        {
            string st;
            for(int i=0;i<k;i++) st.push_back('0' + i);
            return st;
        }

        int N = pow(k, n-1), code, lastDig, codeNext;
        vector<vector<int>> adj(N);
        for(int i=0;i<N;i++)
        {
            code = numOfIndex(i, k), lastDig = code % 10, codeNext = removeFirstDigit(code, n - 1) * 10;
            for(int j=0;j<k;j++) adj[i].push_back(index(codeNext + j, k));
        }

        // for(int i=0;i<N;i++){ cout<<numOfIndex(i, k)<<":  "; for(int e: adj[i]) cout<<numOfIndex(e, k)<<" ";  cout<<endl; } cout<<endl;

        // Now, eulerian tour (guaranteed here)
        string ans;
        vector<int> path = heirholzer(adj, n);
        int pathSize = path.size();
        ans = to_string(numOfIndex(path[0], k));
        if(ans.size() < n - 1) ans = string(n - 1 - ans.size(), '0') + ans;
        for(int i=1;i<pathSize;i++) ans.push_back((numOfIndex(path[i], k) % 10) + '0');

        return ans;
    }
};
