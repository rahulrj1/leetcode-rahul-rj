class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> blue(n), red(n);
        for(vector<int> e: redEdges) red[e[0]].push_back(e[1]);
        for(vector<int> e: blueEdges) blue[e[0]].push_back(e[1]);
        vector<int> ans(n, INT_MAX);
        vector<pair<bool, bool>> vis(n, {false, false});
        
        queue<pair<int, char>> q;
        q.push({0, 'r'});
        q.push({0, 'b'});
        
        int dis = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                pair<int, char> temp = q.front(); q.pop();
                int node = temp.first;
                ans[node] = min(dis, ans[node]);
                if(temp.second == 'r') {
                    vis[node].first = true;
                    for(int nb: blue[node]) {
                        if(!vis[nb].second) {
                            q.push({nb, 'b'});
                        }
                    }
                }
                else {
                    vis[node].second = true;
                    for(int nb: red[node]) {
                        if(!vis[nb].first) {
                            q.push({nb, 'r'});
                        }
                    }
                }
            }
            dis++;
        }
        for(int i=0; i<n; i++) if(ans[i] == INT_MAX) ans[i] = -1;
        return ans;
    }
};