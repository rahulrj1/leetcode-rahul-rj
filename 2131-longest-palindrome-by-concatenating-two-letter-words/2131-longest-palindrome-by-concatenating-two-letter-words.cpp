class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto w: words) mp[w]++;
        bool flag = false;
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            string s = it->first;
            if(s[0] == s[1]) {
                ans += (mp[s]/2)*2;
                if(mp[s]&1) flag = true;
            }
            else {
                string r = s; r[0] = s[1]; r[1] = s[0];
                if(mp.find(r) != mp.end()) ans += min(mp[r], mp[s]);
            }
        }
        if(flag) ans++;
        return 2*ans;
    }
};