class Solution {
public:
    int latestNonConflictJob(vector<pair<int, pair<int, int>>> &v, int i) {
        int l = 0, r = i-1;
        int ans = -1;
        while(l<=r) {
            int m = (l+r)/2;
            if(v[m].first <= v[i].second.first) ans = m, l = m + 1; // v[m].end <= v[i].start
            else r = m - 1;
        }
        return ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> v(n);
        for(int i=0; i<n; i++) v[i].first = endTime[i], v[i].second.first = startTime[i], v[i].second.second = profit[i];
        sort(v.begin(), v.end());
        vector<int> dp(n);
        dp[0] = v[0].second.second;
        for(int i=1; i<n; i++) {
            // find the include profit
            int inclProf = v[i].second.second;
            int l = latestNonConflictJob(v, i); // latest job before this which does not conflict
            if(l != -1) inclProf += dp[l];
                
            // find the not include profit
            int notInclProf = dp[i-1];
            
            dp[i] = max(inclProf, notInclProf);
            // cout<<dp[i]<<" ";
        }
        return dp[n-1];
    }
};