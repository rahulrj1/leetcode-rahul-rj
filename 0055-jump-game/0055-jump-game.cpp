class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0;
        for(int i=0; i<nums.size(); i++) {
            if(range < i) return false;
            range = max(range, nums[i]+i);
        }
        return true;
    }
};