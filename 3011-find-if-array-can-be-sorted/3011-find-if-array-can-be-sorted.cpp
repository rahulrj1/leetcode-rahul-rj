class Solution {
    static int cntSetBits(int num) {
        int cnt = 0;
        for(int i=0; i<=8; i++) {
            if(1&(num>>i)) cnt++;
        }
        return cnt;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int prevSetBits = cntSetBits(nums[0]);
        int l = 0;
        for(int i=1; i<nums.size(); i++) {
            int setBits = cntSetBits(nums[i]);
            if(setBits != prevSetBits) {
                sort(nums.begin() + l, nums.begin() + i);
                l = i;
            }
            prevSetBits = setBits;
        }
        sort(nums.begin() + l, nums.end());
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < nums[i-1]) return false; 
        }
        return true;
    }
};