class Solution {
public:
    int find(int x, vector<int> &parent) {
        if(parent[x] != x) return find(parent[x], parent);
        return x;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        for(int i=0; i<n; i++) parent[i] = i;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int pi = find(i, parent);
                    int pj = find(j, parent);
                    if(pi != pj) {
                        parent[pi] = pj;
                    }
                }
            }
        }
        unordered_set<int> s;
        int ans = stones.size();
        for(int i=0; i<n; i++) s.insert(find(i, parent));
        ans -= s.size();
        return ans;
    }
};