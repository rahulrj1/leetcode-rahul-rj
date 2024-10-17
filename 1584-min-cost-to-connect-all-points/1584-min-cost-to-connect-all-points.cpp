class Solution {
    int findPar(vector<int> &par, int x) {
        if(par[x] == -1) return x;
        return par[x] = findPar(par, par[x]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        
        vector<vector<int> > edges; // weight, i, j
        for(int i=0; i<n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0], y2 = points[j][1]; 
                edges.push_back({abs(x1-x2) + abs(y1-y2), i, j});
            }
        }
        
        sort(edges.begin(), edges.end());
        vector<int> par(n, -1);
        vector<int> rank(n, 0);
        for(vector<int> &e: edges) {
            int wt = e[0];
            int i = e[1], j = e[2];
            
            int p1 = findPar(par, i);
            int p2 = findPar(par, j);
            if(p1 != p2) {
                res += wt;
                
                if(rank[p1] >= rank[p2]) {
                    par[p2] = p1;
                    rank[p1] += rank[p2];
                }
                else {
                    par[p1] = p2;
                    rank[p2] += rank[p1]; 
                }
            }
        }
        return res;
    }
};