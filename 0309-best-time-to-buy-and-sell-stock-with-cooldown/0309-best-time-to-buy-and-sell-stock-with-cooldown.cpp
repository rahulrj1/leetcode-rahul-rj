class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            dp[i] = dp[i-1];
            for(int j=i-1; j>0; j--) {
                int z = j==1 ? 0 : dp[j-2];
                dp[i] = max(dp[i], z + prices[i-1]-prices[j-1]);
            }
        }
        return dp[n];
    }
};