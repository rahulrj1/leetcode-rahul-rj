class Solution {
    int findPar(vector<int> &par, int x) {
        if(par[x] == -1) return x;
        return par[x] = findPar(par, par[x]);
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res;
        for(int i=0; i<edges.size(); i++) {
            reverse(edges[i].begin(), edges[i].end());
            edges[i].push_back(i);
        }
        
        sort(edges.begin(), edges.end());
        vector<int> par(n, -1);
        vector<int> rank(n, 1);
        
        int en = edges.size(); 
        vector<int> e_taken(en, 0);
        int cost = 0;
        for(int i=0; i<en; i++) {
            vector<int> e = edges[i];
            int p1 = findPar(par, e[1]);
            int p2 = findPar(par, e[2]);
            
            if(p1 != p2) {
                if(rank[p1] >= rank[p2]) par[p2] = p1, rank[p1] += rank[p2];
                else par[p1] = p2, rank[p2] += rank[p1];
                e_taken[i] = 1;
                cost += e[0];
            }
        }
        
        vector<int> critical;
        vector<int> pseudo;
        for(int i=0; i<en; i++) {
            if(e_taken[i] == 1) { // edge in MST
                int curr_cost = 0;
                // check if excluding this edge inc the cost of MST
                
                vector<int> par2(n, -1);
                vector<int> rank2(n, 1);
                int cnt = 0;
                for(int j=0; j<en; j++) {
                    if(i == j) continue;
                    vector<int> e = edges[j];
                    int p1 = findPar(par2, e[1]);
                    int p2 = findPar(par2, e[2]);

                    if(p1 != p2) {
                        if(rank2[p1] >= rank2[p2]) par2[p2] = p1, rank2[p1] += rank2[p2];
                        else par2[p1] = p2, rank2[p2] += rank2[p1];
                        curr_cost += e[0];
                        cnt++;
                    }
                }
                if(curr_cost > cost || cnt != n-1) critical.push_back(edges[i][3]);
                else pseudo.push_back(edges[i][3]);
                // cout<<edges[i][3]<<" "<<cost<<" "<<curr_cost<<"  ";
            }
            else { // edge not in MST
                // check if we can make a MST containing this edge
                int curr_cost = edges[i][0];
                
                vector<int> par2(n, -1);
                vector<int> rank2(n, 1);
                par2[edges[i][1]] = edges[i][2];
                rank2[edges[i][2]] += rank2[edges[i][1]];
                
                for(int j=0; j<en; j++) {
                    if(i == j) continue;
                    vector<int> e = edges[j];
                    int p1 = findPar(par2, e[1]);
                    int p2 = findPar(par2, e[2]);

                    if(p1 != p2) {
                        if(rank2[p1] >= rank2[p2]) par2[p2] = p1, rank2[p1] += rank2[p2];
                        else par2[p1] = p2, rank2[p2] += rank2[p1];
                        curr_cost += e[0];
                    }
                }
                if(curr_cost == cost) pseudo.push_back(edges[i][3]);   
            }
        }
        return {critical, pseudo};
    }
};