class Solution {
    int mod = 1e9 + 7;
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        dp[0][0][0] = 1; // base case
        
        for(int len=0; len<n; len++) {
            for(int a=0; a<2; a++) {
                for(int l=0; l<3; l++) {
                    dp[len+1][a][0] = (dp[len+1][a][0] + dp[len][a][l]) % mod;
                    if(a == 0) dp[len+1][a+1][0] = (dp[len+1][a+1][0] + dp[len][a][l]) % mod;
                    if(l < 2) dp[len+1][a][l+1] = (dp[len+1][a][l+1] + dp[len][a][l]) % mod;
                }
            }
        }
        
        int res = 0;
        for(int a=0; a<2; a++) {
            for(int l=0; l<3; l++) {
                res = (res + dp[n][a][l]) % mod;
            }
        }
        return res;
    }
};