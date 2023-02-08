class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currRange = 0, nextRange = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i==nums.size()-1) return jumps;
            nextRange = max(nextRange, i+nums[i]);
            if(i==currRange) currRange = nextRange, jumps++;
        }
        return -1;
    }
};