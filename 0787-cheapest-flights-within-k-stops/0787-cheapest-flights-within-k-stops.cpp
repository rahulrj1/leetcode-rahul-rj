class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<vector<int>>> mp;
        for(vector<int> &f: flights) mp[f[0]].push_back({f[1], f[2]});
        vector<vector<int>> cost(n, vector<int>(k+2, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q; 
        q.push({0, src, 0});
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                vector<int> v = q.top(); q.pop();
                if(cost[v[1]][v[2]] <= v[0]) continue;
                cost[v[1]][v[2]] = v[0];
                if(v[2] == k+1) continue;

                for(vector<int> nb: mp[v[1]]) {
                    if(cost[nb[0]][v[2]+1] > nb[1]+v[0]) q.push({nb[1]+v[0], nb[0], v[2]+1});
                }
            }
        }
        int ans = INT_MAX;
        for(auto c: cost[dst]) ans = min(ans, c);
        return ans == INT_MAX ? -1 : ans;
    }
};