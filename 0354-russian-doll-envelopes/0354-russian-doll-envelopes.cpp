class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        vector<int> LIS;
        for(vector<int> &envelope: envelopes) {
            int idx = lower_bound(LIS.begin(), LIS.end(), envelope[1]) - LIS.begin();
            if(idx == LIS.size()) LIS.push_back(envelope[1]);
            else LIS[idx] = envelope[1];
        }
        return LIS.size();
    }
};