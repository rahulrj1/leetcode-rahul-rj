class Solution {
public:
    vector<int> helper(int node, unordered_map<int, vector<int>> &adjlist, vector<bool> &vis, string &labels, vector<int> &ans) {
        vis[node] = true;
        vector<int> temp(26, 0);
        temp[labels[node]-'a']++;
        for(int nb: adjlist[node]) {
            if(vis[nb]) continue;
            
            vector<int> nbt = helper(nb, adjlist, vis, labels, ans);
            for(int i=0; i<26; i++) temp[i] += nbt[i];
        }
        ans[node] += temp[labels[node]-'a'];
        return temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adjlist;
        for(vector<int> e: edges) {
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }
        
        vector<int> ans(n, 0);
        vector<bool> vis(n, false);
        helper(0, adjlist, vis, labels, ans);
        return ans;
    }
};