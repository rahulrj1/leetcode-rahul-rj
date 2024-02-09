class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> dp(n+1, 0); // dp[i] represents the size of largest subset ending with nums[i-1]
        for(int i=1; i<=n; i++) {
            dp[i] = 1;
            for(int j=1; j<i; j++) {
                if(nums[i-1]%nums[j-1] == 0) {
                    if(dp[j] + 1 > dp[i]) dp[i] = 1+dp[j];
                }
            }
        }
        int size = 1, z = nums[0];
        for(int i=1; i<=n; i++) {
            if(dp[i] > size) size = dp[i], z = nums[i-1];
        }
        
        vector<int> res;
        for(int i=n; i>=1; i--) {
            if((dp[i] == size) && (z%nums[i-1] == 0)) res.push_back(nums[i-1]), size--, z = nums[i-1];
        }
        return res;
    }
};