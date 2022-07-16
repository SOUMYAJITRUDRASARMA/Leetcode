class Solution {
public:
    bool dfs(int cur, vector<vector<int>> &adj, unordered_map<int, bool> &available)
    {
        if(available.find(cur) != available.end()) return available[cur];

        if(adj[cur].empty()) return available[cur] = false;

        available[cur] = false; // can contain loops, so by default if none is present is the loop, we want false as answer

        bool ans = true;
        for(int dependency: adj[cur])
        {
            if(!dfs(dependency, adj, available))
            {
                ans = false;
                break;
            }
        }

        return available[cur] = ans;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int cnt = 0, n = recipes.size();
        unordered_map<string, int> m; // node number
        vector<vector<int>> adj; // dependencies  -  recipe -> ingredients
        for(int i=0;i<n;i++)
        {
            if(m.find(recipes[i]) == m.end()) m[recipes[i]] = cnt++, adj.push_back(vector<int>());
            for(string &ingredient: ingredients[i])
            {
                if(m.find(ingredient) == m.end()) m[ingredient] = cnt++, adj.push_back(vector<int>());
                adj[m[recipes[i]]].push_back(m[ingredient]);
            }
        }

        unordered_map<int, bool> available; // like dp, available or not
        for(string &supply: supplies)
            if(m.find(supply) != m.end()) available[m[supply]] = true;

        vector<string> ans;
        for(string &recipe: recipes)
            if(dfs(m[recipe], adj, available)) ans.push_back(recipe);

        return ans;
    }
};
