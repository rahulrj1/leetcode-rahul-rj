class Solution {
    int findParent(int &u, vector<int> &par) {
        if(par[u] == -1) return u;
        return par[u] = findParent(par[u], par);
    }
    
    bool do_union(int &u, int &v, vector<int> &par, vector<int> &rank) {
        int p1 = findParent(u, par);
        int p2 = findParent(v, par);
        
        if(p1 == p2) return true;
        if(rank[p1] >= rank[p2]) par[p2] = p1;
        else par[p1] = p2;
        
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n, -1);
        vector<int> rank(n, -1);
        
        for(vector<int> &edge: edges) {
            int u = edge[0]-1, v = edge[1]-1;
            bool isCycle = do_union(u, v, par, rank);
            if(isCycle) return edge;
        }
        
        return {};
    }
};