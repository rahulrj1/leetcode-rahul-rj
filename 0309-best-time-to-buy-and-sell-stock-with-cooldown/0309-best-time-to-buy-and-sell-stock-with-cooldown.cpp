class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0; dp[1] = 0;
        int z = -prices[0];
        for(int i=2; i<=n; i++) {
            dp[i] = max(dp[i-1], prices[i-1]+z);
            z = max(z, dp[i-2] - prices[i-1]);
        }
        return dp[n];
    }
};