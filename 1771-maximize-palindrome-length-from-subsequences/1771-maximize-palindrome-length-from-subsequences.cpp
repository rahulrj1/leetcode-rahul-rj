class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.length();
        
        vector<vector<int> > dp(n, vector<int> (n, 0));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        for(int len=2; len<=n; len++) {
            for(int i=0; i+len-1<n; i++) {
                int j=i+len-1;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        int res = 0;
        int n1 = word1.length(), n2 = word2.length(); 
        for(int i=0; i<n1; i++) {
            for(int j=n1; j<n1+n2; j++) {
                if(s[i] == s[j]) {
                    res = max(res, 2 + dp[i+1][j-1]);
                }
            }
        }
        return res;
    }
};