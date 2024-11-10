class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k == 0) return 1;
        int l=0, r=0; // subarray from l till r-1
        int z=0, res = 1e6;
        vector<int> cnt(32, 0);
        while(l < nums.size()) {
            if(z < k && r < nums.size()) {
                // include nums[r] in OR
                for(int i=0; i<32; i++) {
                    if(1&(nums[r]>>i)) cnt[i]++;
                }
                // update z and r
                z |= nums[r++];
            }
            else {
                // excluse nums[l] in OR
                for(int i=0; i<32; i++) {
                    if(1&(nums[l]>>i)) {
                        cnt[i]--;
                        if(cnt[i] == 0) z &= ~(1<<i);
                    }
                }
                // update z
                l++;
            }
            if(z >= k) res = min(res, r-l);
        }
        if(res == 1e6) res = -1;
        return res;
    }
};