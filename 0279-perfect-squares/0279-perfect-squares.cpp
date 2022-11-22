class Solution {
public:
    int numSquares(int n) {
        int z = sqrt(n);
        int dp[n+1][z+1]; // dp[i][j] means to make i using first j squares
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++) {
            dp[i][0] = 1e5;
            for(int j=1; j<=z; j++) {
                dp[i][j] = dp[i][j-1];
                if(j*j <= i) dp[i][j] = min(dp[i][j], 1+dp[i - j*j][j]);
            }
        }
        return dp[n][z];
    }
};