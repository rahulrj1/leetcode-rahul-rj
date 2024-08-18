class Solution {
public:
    int nthUglyNumber(int n) {
        int n2=1, n3=1, n5=1;
        int dp[n+1]; dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = min({dp[n2]*2, dp[n3]*3, dp[n5]*5});
            if(dp[i] == dp[n2]*2) n2++;
            if(dp[i] == dp[n3]*3) n3++;
            if(dp[i] == dp[n5]*5) n5++;
        }
        return dp[n];
    }
};