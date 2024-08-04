class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adjlist(n);
        for(vector<int> &e: edges) adjlist[e[0]].push_back(e[1]), adjlist[e[1]].push_back(e[0]);
        
        int res = 1005;
        for(int i=0; i<n; i++) {
            // find the shortest cycle containing vertex i
            vector<int> dist(n, 1005);
            vector<int> par(n, -1);
            dist[i] = 0;
            
            queue<int> q; q.push(i);
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                for(int child: adjlist[curr]) {
                    if(dist[child] == 1005) {
                        par[child] = curr;
                        dist[child] = dist[curr] + 1;
                        q.push(child);
                    }
                    else if(par[curr] != child){
                        res = min(res, dist[curr] + dist[child] + 1);
                    }
                }
            }
        }
        
        if(res == 1005) res = -1;
        return res;
    }
};