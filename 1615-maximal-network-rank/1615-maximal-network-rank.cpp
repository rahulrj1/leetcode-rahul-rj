class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> rank(n, 0);
        vector<vector<bool>> adjmat(n, vector<bool> (n, false));
        for(vector<int> road: roads) rank[road[0]]++, rank[road[1]]++, adjmat[road[0]][road[1]] = true, adjmat[road[1]][road[0]] = true;
        
        
        int maxRank = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                maxRank = max(maxRank, rank[i] + rank[j] - adjmat[i][j]);
            }
        }
        return maxRank;
    }
};