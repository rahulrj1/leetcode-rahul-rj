class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        for(int m=l; m<=r; m++) {
            if(nums[m] == 0) swap(nums[l++], nums[m]);
            else if(nums[m] == 2) swap(nums[r--], nums[m--]);
        }
    }
};