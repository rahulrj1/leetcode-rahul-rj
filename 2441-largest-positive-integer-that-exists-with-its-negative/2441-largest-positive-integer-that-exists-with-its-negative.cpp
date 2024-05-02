class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool> isPres(1001, false);
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]<0) isPres[-nums[i]] = true;
        }
        int res = -1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0 && isPres[nums[i]]) res = max(res, nums[i]);
        }
        return res;
    }
};