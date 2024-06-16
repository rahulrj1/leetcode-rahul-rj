class Solution {
public:
    void helper(int idx, vector<int> &subset, vector<int> &nums, int &res, int &k) {
        if(subset.size() > 0) {
            res++;
        }
        for(int i=idx; i<nums.size(); i++) {
            bool isBeautiful = true;
            for(int s: subset) if(s == nums[i] - k) {isBeautiful = false; break;}
            if(!isBeautiful) continue;
            subset.push_back(nums[i]);
            helper(i+1, subset, nums, res, k);
            subset.pop_back();
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        vector<int> subset;
        helper(0, subset, nums, res, k);
        return res;
    }
};