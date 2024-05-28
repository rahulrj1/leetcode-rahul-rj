class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int res = 0;
        vector<int> prefCost(n+1, 0);
        for(int i=0; i<n; i++) {
            prefCost[i+1] = abs(s[i]-t[i]) + prefCost[i];
            int l = 0, r = i+1;
            while(l <= r) {
                int m = (l+r)/2, temp = prefCost[i+1] - prefCost[m];
                if(temp <= maxCost) r = m-1, res = max(res, i+1-m);
                else l = m+1;
            }
        }
        return res;
    }
};