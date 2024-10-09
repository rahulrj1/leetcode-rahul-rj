class Solution {
public:
    static int findPar(vector<int> &par, int x) {
        if(par[x] == -1) return x;
        return par[x] = findPar(par, par[x]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        // find number of groups. let it be g
        // ans will be g-1
        
        vector<int> par(n, -1);
        vector<int> rank(n, -1);
        
        for(vector<int> &c: connections) {
            int p1 = findPar(par, c[0]);
            int p2 = findPar(par, c[1]);
            if(p1 != p2) {
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
        
        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            int p = findPar(par, i);
            st.insert(p);
        }
        int g = st.size();
        return g-1;
    }
};