#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007


class Solution {
public:
    bool dfsHasCycleBuildTopSort(int node, int numCourses, vector<vector<int>> &adj, vector<bool> &visited, set<int> &alphaNodes, vector<int> &topSortOrder)
    {
        visited[node]= true;

        for(int v: adj[node])
        {
            if(alphaNodes.find(v) != alphaNodes.end())
                return true;

            if(visited[v])
                continue;

            alphaNodes.insert(v);
            if(dfsHasCycleBuildTopSort(v, numCourses, adj, visited, alphaNodes, topSortOrder))
                return true;
            alphaNodes.erase(v);
        }

        // post-visit
        topSortOrder.push_back(node); // as multiple path ,

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // building adjacency list of directed graph
        vector<vector<int>> adj(numCourses);
        for(vector<int> v: prerequisites)
            adj[v[1]].push_back(v[0]);

        vector<int> topSortOrder;
        vector<int> emptyVect;
        vector<bool> visited(numCourses, false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                set<int> s({i});
                // vector<bool> visited2(numCourses, false);
                if(dfsHasCycleBuildTopSort(i, numCourses, adj, visited, s, topSortOrder))
                    return emptyVect;

                // for(int i=0;i<numCourses;i++)
                //     visited[i] = visited[i] || visited2[i];
            }
        }

        reverse(topSortOrder.begin(), topSortOrder.end());
        return topSortOrder;
    }
};

int main()
{
    vector<vector<int>> prerequisites(1);
    prerequisites[0].push_back(0);
    prerequisites[0].push_back(1);

    vector<int> order = (new Solution)->findOrder(2, prerequisites);
    for(int e: order) cout<<e<<"  "; cout<<endl;
    return 0;
}
