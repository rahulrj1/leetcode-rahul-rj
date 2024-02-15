class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long pref[n], res = -1; 
        pref[0] = nums[0]; pref[1] = pref[0] + nums[1];
        for(int i=2; i<n; i++) {
            if(pref[i-1] > nums[i]) res = max(res, pref[i-1] + nums[i]);
            pref[i] = pref[i-1] + nums[i];
        }
        return res;
    }
};