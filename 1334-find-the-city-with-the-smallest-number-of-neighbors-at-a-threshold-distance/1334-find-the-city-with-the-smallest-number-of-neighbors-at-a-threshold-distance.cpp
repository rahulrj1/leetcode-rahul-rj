class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > graph(n, vector<int> (n, 1e7));
        
        for(int i=0; i<n; i++) graph[i][i] = 0;
        for(vector<int> &e: edges) graph[e[0]][e[1]] = e[2], graph[e[1]][e[0]] = e[2];
                
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        
        vector<pair<int, int>> reachableCities(n, {0, 0});
        for(int i=0; i<n; i++) {
            reachableCities[i].second = i;
            for(int j=0; j<n; j++)
                if(graph[i][j] <= distanceThreshold && i != j) reachableCities[i].first++, reachableCities[j].first++;
        }
        sort(reachableCities.begin(), reachableCities.end(), [&](pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        return reachableCities[0].second;
    }
};