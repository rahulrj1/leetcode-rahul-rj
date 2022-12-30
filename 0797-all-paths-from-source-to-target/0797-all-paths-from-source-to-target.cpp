class Solution {
public:
    void helper(vector<vector<int>> &graph, int node, vector<int> &temp, vector<vector<int>> &ans) {
        temp.push_back(node);
        if(node == graph.size()-1) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int nb: graph[node]) {
            helper(graph, nb, temp, ans);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(graph, 0, temp, ans);
        return ans;
    }
};