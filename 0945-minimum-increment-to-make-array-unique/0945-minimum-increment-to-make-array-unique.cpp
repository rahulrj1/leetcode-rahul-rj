class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, curr = nums[0]-1;
        for(int num: nums) {
            if(num <= curr) curr++;
            else curr = num;
            res += curr - num;
        }
        return res;
    }
};