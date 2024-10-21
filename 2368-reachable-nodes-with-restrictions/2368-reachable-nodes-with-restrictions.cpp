class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adjlist(n);
        for(vector<int> &e: edges) adjlist[e[0]].push_back(e[1]), adjlist[e[1]].push_back(e[0]);
        
        unordered_set<int> s;
        for(int &r: restricted) s.insert(r);
        
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0); vis[0] = true;
        int res = 1;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for(int nbr: adjlist[curr]) {
                if(!vis[nbr] && s.find(nbr) == s.end()) {
                    vis[nbr] = true;
                    q.push(nbr);
                    res++;
                }
            }
        }
        return res;
    }
};