class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        
        // adjlist[i] has all the routes which containes stop i
        unordered_map<int, vector<int>> adjlist;
        for(int i=0; i<routes.size(); i++) {
            for(int &stop: routes[i]) {
                adjlist[stop].push_back(i);
            }
        }
        
        queue<int> q;
        vector<bool> vis(routes.size(), false);
        
        int level = 0;
        for(int &route: adjlist[source]) q.push(route), vis[route] = true;
        while(!q.empty()) {
            int sz = q.size();
            level++;
            while(sz--) {
                int curr = q.front(); q.pop();
                for(int &stop: routes[curr]) {
                    if(stop == target) return level;
                    
                    for(int &route: adjlist[stop]) {
                        if(vis[route]) continue;
                        
                        q.push(route);
                        vis[route] = true;
                    }
                }
            }
        }
        return -1;
    }
};