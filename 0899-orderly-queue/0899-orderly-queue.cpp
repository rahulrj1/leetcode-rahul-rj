class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            int n = s.length();
            string ans = s;
            for(int i=0; i<n; i++) {
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                ans = min(s, ans);
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};