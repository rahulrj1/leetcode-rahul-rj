class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int z = 0; for(int i: nums) z ^= i;
        for(int i=n-1; i>=0; i--) {
            ans[i] = 0;
            for(int j=0; j<maximumBit; j++) if((z&(1<<j)) == 0) ans[i] |= (1<<j);
            z ^= nums[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};