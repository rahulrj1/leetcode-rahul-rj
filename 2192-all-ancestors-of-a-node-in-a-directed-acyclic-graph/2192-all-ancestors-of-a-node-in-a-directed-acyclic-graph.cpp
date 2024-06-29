class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjlist;
        vector<int> indegree(n, 0);
        for(vector<int> &edge: edges) indegree[edge[1]]++, adjlist[edge[0]].push_back(edge[1]);
        queue<int> q;
        for(int i=0; i<n; i++) if(indegree[i] == 0) q.push(i);
        
        vector<unordered_set<int>> res(n);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(int &nb: adjlist[node]) {
                for(int a: res[node]) res[nb].insert(a);
                res[nb].insert(node);
                
                if(indegree[nb]-- == 1) {
                    q.push(nb);    
                }
            }
        }
        vector<vector<int>> ans(n);
        for(int i=0; i<n; i++) {
            for(int z: res[i]) ans[i].push_back(z);
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};