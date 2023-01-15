class Solution {
public:
    int findParent(int i, vector<int> &parent) {
        if(parent[i] != i) return parent[i] = findParent(parent[i], parent);
        return i;
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        map<int, vector<int>> valuesToNodes;
        for(int i=0; i<vals.size(); i++) valuesToNodes[vals[i]].push_back(i);
        
        int goodPaths = 0;
        vector<int> parent(vals.size());
        for(int i=0; i<parent.size(); i++) parent[i] = i;
        vector<bool> vis(vals.size(), false);
        
        for(auto &it: valuesToNodes) {
            int value = it.first;
            vector<int> nodes = it.second;
            
            for(int node: nodes) {
                
                for(int nb: adj[node]) {
                    if(vals[node] >= vals[nb]) {
                        int node_par = findParent(node, parent), nb_par = findParent(nb, parent);
                        if(node_par != nb_par) parent[nb_par] = node_par;
                    }
                }
            }
            
            map<int, int> group;
            for(int node: nodes) {
                int node_par = findParent(node, parent);
                group[node_par]++;
            }
            for(auto &it: group) {
                int g = it.second;
                goodPaths += g*(g+1)/2;
            }
            
        }
        return goodPaths;
    }
};