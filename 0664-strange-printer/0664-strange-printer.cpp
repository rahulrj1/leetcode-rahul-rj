class Solution {
public:
    string preCalc(string &s) {
        string res;
        for(char &c: s) if(res.size() == 0 || res.back() != c) res += c;
        return res;
    }
    
    int strangePrinter(string s) {
        s = preCalc(s);
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) dp[i][i] = 1;
        
        for(int len=2; len<=n; len++) {
            for(int st=0; st+len-1<n; st++) {
                int end = st + len - 1;
                dp[st][end] = len;
                
                for(int split = 0; split < len - 1; split++) {
                    int temp = dp[st][st+split] + dp[st+split+1][end];
                    if(s[st+split] == s[end]) temp--;
                    dp[st][end] = min(dp[st][end], temp);
                }
            }
        }
        
        return dp[0][n-1];
    }
};