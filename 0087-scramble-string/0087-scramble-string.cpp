class Solution {
public:
    unordered_map<string, int> dp;
    bool helper(string s, string t) {
        int n = s.length();
        if(n == 1) return s == t;
        string key = s + "$" + t;
        if(dp.find(key) != dp.end()) return dp[key];
        for(int i=1; i<n; i++) {
            if((helper(s.substr(0, i), t.substr(0, i)) && helper(s.substr(i), t.substr(i))) || (helper(s.substr(0, i), t.substr(n-i)) && helper(s.substr(i), t.substr(0, n-i)))) return dp[key] = true;
        }
        return dp[key] = false;
    }
    
    bool isScramble(string s1, string s2) {
        return helper(s1, s2);
    }
};