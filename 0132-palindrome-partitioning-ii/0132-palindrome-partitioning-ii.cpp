class Solution {
public:
    vector<int> dp;
    bool isPal(string &s, int l, int r) {
        while(l<r) {if(s[l] != s[r]) return false; else l++, r--;}
        return true;
    }
    
    int helper(string &s, int idx) {
        if(idx == s.length() ) return 0;
        if(dp[idx] != -1) return dp[idx];
        int res = s.length() - idx - 1;
        for(int i=idx; i<s.length() - 1; i++) {
            if(isPal(s, idx, i)) {
                res = min(res, 1 + helper(s, i+1));
            }
        }
        if(isPal(s, idx, s.length()-1)) res = 0;
        return dp[idx] = res;
    }
    
    
    int minCut(string s) {
        vector<int> v(s.length() + 1, -1);
        dp = v;
        return helper(s, 0);
    }
};