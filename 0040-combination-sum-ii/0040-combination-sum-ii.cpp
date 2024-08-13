class Solution {
public:
    void findans(vector<vector<int>> &ans, vector<int> &temp, vector<int> &c, int target, int sum, int index) {
        if(sum >= target) {
            if(sum==target) ans.push_back(temp);
            return;
        }
        for(int i=index; i<c.size(); i++) {
            if(i!=index && c[i]==c[i-1]) continue;
            temp.push_back(c[i]);
            findans(ans, temp, c, target, sum+c[i], i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        findans(ans, temp, candidates, target, 0, 0);
        return ans;
    }
};