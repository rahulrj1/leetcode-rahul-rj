class Solution {
public:
    int helper(vector<int> &nums, int last, int target) {
        if(last == -1) return target == 0;
        return helper(nums, last-1, target-nums[last]) + helper(nums, last-1, target+nums[last]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums, n-1, target);
    }
};