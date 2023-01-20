class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int idx) {
        if(temp.size() > 1) ans.push_back(temp);
        
        unordered_set<int> s;
        for(int i=idx; i<nums.size(); i++) {
            if(s.find(nums[i]) != s.end()) continue;
            
            s.insert(nums[i]);
            if(temp.size() == 0 || temp.back() <= nums[i]) {
                temp.push_back(nums[i]);
                helper(ans, temp, nums, i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, nums, 0);
        return ans;
    }
};