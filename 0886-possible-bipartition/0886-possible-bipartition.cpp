class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &adjlist, vector<int> &group, int node, int g) {
        group[node] = g;
        for(int nb: adjlist[node]) {
            if(group[nb] == g) return false;
            else if(group[nb] == -1 && (!dfs(adjlist, group, nb, (g+1)%2))) return false; 
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjlist;
        for(vector<int> v: dislikes) {
            adjlist[v[0]].push_back(v[1]);
            adjlist[v[1]].push_back(v[0]);
        }
        
        vector<int> group(n+1, -1);
        for(int i=1; i<=n; i++) {
            if(group[i] == -1) {
                if(!dfs(adjlist, group, i, 1)) return false;
            }
        }
        return true;
    }
};