class Solution {
public:
    long long dfs(int node, int par, vector<vector<int>> &adjlist, int seats, long long &ans) {
        int person = 1;
        for(int nb: adjlist[node]) {
            if(nb == par) continue;
            person += dfs(nb, node, adjlist, seats, ans);
        }
        ans += (person/seats) + ((person % seats) != 0);
        return person;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adjlist(roads.size() + 2);
        for(vector<int> e: roads) {
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }
        
        long long ans = 0;
        for(int nb: adjlist[0]) {
            dfs(nb, 0, adjlist, seats, ans);
        }
        return ans;
    }
};