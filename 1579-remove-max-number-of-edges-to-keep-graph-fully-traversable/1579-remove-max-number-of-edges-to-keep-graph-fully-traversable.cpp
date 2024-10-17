class Solution {
    int findPar(vector<int> &pa, vector<int> &pb, int x) {
        if(pa[x] == -1) return x;
        pa[x] = findPar(pa, pb, pa[x]);
        return pb[x] = pa[x];
    }
    int findPar(vector<int> &p, int x) {
        if(p[x] == -1) return x;
        return p[x] = findPar(p, p[x]);
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(), edges.rend()); // all type 3 edges come first
        vector<int>pa(n, -1);
        vector<int>ra(n, 1);
        vector<int>pb(n, -1);
        vector<int>rb(n, 1);
        int e1 = 0, e2 = 0, e3 = 0;
        
        for(vector<int> &e: edges) {
            if(e[0] == 3) {
                int p1 = findPar(pa, pb, e[1]-1);
                int p2 = findPar(pa, pb, e[2]-1);
                
                if(p1 != p2) {
                    e3++;
                    if(ra[p1] >= ra[p2]) {
                        pa[p2] = p1, pb[p2] = p1;
                        ra[p1] += ra[p2], rb[p1] += rb[p2];
                    }
                    else{
                        pa[p1] = p2, pb[p1] = p2;
                        ra[p2] += ra[p1], rb[p2] += rb[p1];
                    }
                }
            }
            else if(e[0] == 1) {
                int p1 = findPar(pa, e[1]-1);
                int p2 = findPar(pa, e[2]-1);
                
                if(p1 != p2) {
                    e1++;
                    if(ra[p1] >= ra[p2]) pa[p2] = p1, ra[p1] += ra[p2];
                    else pa[p1] = p2, ra[p2] += ra[p1];
                }
            }
            else {
                int p1 = findPar(pb, e[1]-1);
                int p2 = findPar(pb, e[2]-1);
                
                if(p1 != p2) {
                    e2++;
                    if(rb[p1] >= rb[p2]) pb[p2] = p1, rb[p1] += rb[p2];
                    else pb[p1] = p2, rb[p2] += rb[p1];
                }
            }
        }
        if((e3+e1 != n-1) || (e3+e2 != n-1)) return -1;
        return edges.size() - (e1+e2+e3);
    }
};