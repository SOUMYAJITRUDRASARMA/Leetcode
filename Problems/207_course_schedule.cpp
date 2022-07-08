#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007


class Solution {
public:
    bool dfsHasCycle(int node, int numCourses, vector<vector<int>> &adj, vector<bool> &visited, set<int> &alphaNodes)
    {
        visited[node]= true;

        for(int v: adj[node])
        {
            if(alphaNodes.find(v) != alphaNodes.end())
                return true;

            if(visited[v])
                continue;

            alphaNodes.insert(v);
            if(dfsHasCycle(v, numCourses, adj, visited, alphaNodes))
                return true;
            alphaNodes.erase(v);
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // a topological sort is possible if graph is acyclic
        // so, has cycles -> false, acyclic -> true

        // building adjacency list of directed graph
        vector<vector<int>> adj(numCourses);
        for(vector<int> v: prerequisites)
            adj[v[1]].push_back(v[0]);

        // for(vector<int> v: adj){ for(int e: v) cout<<e<<"  "; cout<<endl; } // testing

        vector<bool> visited(numCourses, false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                set<int> s({i});
                vector<bool> visited2(numCourses, false);
                if(dfsHasCycle(i, numCourses, adj, visited2, s))
                    return false;

                for(int i=0;i<numCourses;i++)
                    visited[i] = visited[i] || visited2[i];
            }
        }

        return true;
    }
};

/*int main()
{
    vector<vector<int>> prerequisites(5);
    prerequisites[0].push_back(2);
    prerequisites[0].push_back(0);
    prerequisites[1].push_back(1);
    prerequisites[1].push_back(0);
    prerequisites[2].push_back(3);
    prerequisites[2].push_back(1);
    prerequisites[3].push_back(3);
    prerequisites[3].push_back(2);
    prerequisites[4].push_back(1);
    prerequisites[4].push_back(3);

    cout<< (new Solution)->canFinish(4, prerequisites) <<endl;
    return 0;
}*/
