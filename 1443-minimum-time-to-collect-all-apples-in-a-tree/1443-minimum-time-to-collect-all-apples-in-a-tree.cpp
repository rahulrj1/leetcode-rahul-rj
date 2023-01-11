class Solution {
public:
    bool helper(int node, vector<bool> &vis, unordered_map<int, vector<int>> &adjlist, vector<bool> &hasApple, int &ans) {
        bool flag = false;
        vis[node] = true;
        if(hasApple[node]) flag = true;
        for(int nb: adjlist[node]) {
            if(vis[nb]) continue;
            if(helper(nb, vis, adjlist, hasApple, ans)) flag = true;
        }
        if(flag && node != 0) ans += 2;
        return flag;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adjlist;
        for(vector<int> e: edges) {
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }
        
        int ans = 0;
        vector<bool> vis(n, false);
        helper(0, vis, adjlist, hasApple, ans);
        return ans;
    }
};