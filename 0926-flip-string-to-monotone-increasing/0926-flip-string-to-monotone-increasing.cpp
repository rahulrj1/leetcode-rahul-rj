class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int oneright = 0, oneleft = 0;
        for(int i=0; i<n; i++) if(s[i] == '1') oneright++;
        int res = min(oneright, n-oneright);
        for(int i=0; i<=n; i++) {
            res = min(res, (n-i-oneright) + oneleft);
            if(i != n && s[i] == '1') oneright--, oneleft++;
        }
        return res;
    }
};