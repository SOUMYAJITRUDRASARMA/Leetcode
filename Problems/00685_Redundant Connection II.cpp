// https://www.youtube.com/watch?v=d0tqBMRZ6UQ

class Solution {
public:
    int findRep(int i, vector<int> &v)
    {
        if(v[i] < 0) return i;
        else return v[i] = findRep(v[i], v);
    }

    bool unionDS(int a, int b, vector<int> &v)
    {
        int aRep, bRep;
        aRep = findRep(a, v);
        bRep = findRep(b, v);

        if(aRep == bRep) return false;

        int aSize, bSize;
        aSize = -v[aRep];
        bSize = -v[bRep];

        if(aSize <= bSize)
        {
            v[aRep] = bRep;
            v[bRep] = -(aSize + bSize);
        }
        else
        {
            v[bRep] = aRep;
            v[aRep] = -(aSize + bSize);
        }

        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // R -> Root Node , NR -> Non Root Node
        // 3 cases -> double parent (NR -> NR) , cycle (NR -> R edge), double parent and cycle (NR -> NR (any of first node's ancestor) like a Linked List)
        // SOLVING -> keep track of indegree increasing edges
        // if true cycle detected (DSU) and no indegree is 2 till now -> that edge is the answer [In this case DSU OK -> only 1 edge extra]

        int n = edges.size(), a, b, cur = -1, bl1, bl2, bl3; // bl3 is cycle causing edge
        vector<int> v(n + 1, -1);
        vector<int> indegree(n + 1, -1); // if not 1, it stores due to which edge number, our nth node's indegree became 1
        bool isBlackListed = false, isCyclePresent = false;

        for(vector<int> &edge: edges)
        {
            cur++;
            a = edge[0], b = edge[1];


            // if(isBlackListed) continue;
            if(indegree[b] != -1)
            {
                // cur is current edge and indegree[b] is prev edge both pointing to b
                // if cycle is also present, that edge in cycle is the answer, else the latter one (cur) (acc to question)
                // we blacklist these 2 edges' indexes and later check for cycle  :)
                bl1 = indegree[b], bl2 = cur;  // bl2 is the later found edge if cycle not found
                isBlackListed = true;

                if(isCyclePresent) return edges[bl1]; // bl2 not yet checked still cycle present, so bl1 is the answer

                continue;
            }
            indegree[b] = cur;
            if(findRep(a, v) != findRep(b, v)) unionDS(a, b, v);
            else
            {
                if(isBlackListed)
                {
                    // this means our second blacklisted edge didnot solve the case
                    // so first one is the answer
                    return edges[bl1];
                }
                else bl3 = cur, isCyclePresent = true; // no blacklist yet cycle detected but might get blacklisted in future
            }
        }

        // indegree not increased and cycle present, so cycle causing edge is the answer
        if(isCyclePresent) return edges[bl3];

        // if after not processing the blacklisted edge, no cycle detected then that is the answer
        return(edges[bl2]);
    }
};
