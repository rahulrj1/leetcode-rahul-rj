class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = -1;
        for(int k=0; k<=n; k++) {
            // move i to proper place
            while(i+1 < n && nums[i+1] < k) i++;
            if(k == n-i-1) return k;
        }
        return -1;
    }
};