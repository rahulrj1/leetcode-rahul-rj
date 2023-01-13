class Solution {
public:
    int findAns(int node, vector<int> &parent, unordered_map<int, vector<int>> &child, vector<bool> &vis) {
        vis[node] = true;
        int ans = 1;
        for(int nb: child[node]) {
            if(vis[nb]) continue;
            ans = max(ans, 1 + findAns(nb, parent, child, vis));
        }
        if(parent[node] != -1 && vis[parent[node]] == false) ans = max(ans, 1 + findAns(parent[node], parent, child, vis));
        return ans;
    }
    
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int, vector<int>> child;
        for(int i=0; i<parent.size(); i++) {
            if(parent[i] != -1) {
                if(s[parent[i]] == s[i]) parent[i] = -1;
                else child[parent[i]].push_back(i);
            }
        }
        
        vector<bool> vis(parent.size(), false);
        int ans = 1;
        for(int i=0; i<parent.size(); i++) {
            if(parent[i] != -1) continue;
            
            int fn = -1;
            queue<int> q; q.push(i);
            while(!q.empty()) {
                int sz = q.size();
                while(sz--) {
                    int node = q.front(); q.pop();
                    fn = node;
                    for(int nb: child[node]) q.push(nb);
                }
            }
            int tempans = findAns(fn, parent, child, vis);
            ans = max(ans, tempans);
        }
        return ans;
    }
};