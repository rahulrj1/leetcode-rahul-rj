class Solution {
public:
    vector<vector<int>> v;
    vector<int> count, res;
    
    void dfs(int node, int par = -1) {
        for(int child: v[node]) {
            if(child == par) continue;
            dfs(child, node);
            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
        count[node]++;
    }
    
    void dfs2(int node, int par = -1) {
        int n = v.size();
        for(int child: v[node]) {
            if(child == par) continue;
            res[child] = res[node] - count[child] + n - count[child];
            dfs2(child, node);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n); res.resize(n); count.resize(n);
        
        for(vector<int> &e:edges) {
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }
        
        dfs(0);
        dfs2(0);
        
        return res;
    }
};