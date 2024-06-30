class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adjlist;
        for(vector<int> &road: roads) adjlist[road[0]].push_back(road[1]), adjlist[road[1]].push_back(road[0]);
        
        int maxRank = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int rank_i = adjlist[i].size(), rank_j = adjlist[j].size();
                int isRoad = 0;
                for(int nbr: adjlist[i]) if(nbr == j) {isRoad = 1; break;}
                maxRank = max(maxRank, rank_i + rank_j - isRoad);
            }
        }
        return maxRank;
    }
};