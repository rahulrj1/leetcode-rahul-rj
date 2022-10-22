class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); if(n==1) return;
        int z=n-2; // z is the nearest index from last such that nums[z] < nums[z+1]
        while(z >= 0 && nums[z] >= nums[z+1]) z--;
        if(z == -1) { // base case: when nums is a decreasing array
            reverse(nums.begin(), nums.end());
            return;
        }
        int just_greater=z+1; // just greater than nums[z]
        for(int i=z+2; i<n; i++) if(nums[i]>nums[z]) just_greater = i;
        swap(nums[z], nums[just_greater]);
        reverse(nums.begin()+z+1, nums.end());
    }
};