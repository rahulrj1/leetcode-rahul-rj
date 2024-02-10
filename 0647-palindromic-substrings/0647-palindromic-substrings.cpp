class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if(n == 1) return n;
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i=0; i<n; i++) dp[i][i] = true; 
        int res = n;
        
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) dp[i][i+1] = true, res++;
        }
        for(int len = 3; len <= n; len++) {
            for(int i=0; i+len-1 < n; i++) {
                if(s[i] == s[i+len-1] && dp[i+1][i+len-2]) dp[i][i+len-1] = true, res++;
            }
        }
        return res;
    }
};