class Solution {
public:
    int helper(int id, vector<int> &dp, vector<int> &arr, int d) {
        if(dp[id] != -1) return dp[id];
        
        dp[id] = 1;
        for(int i=id+1; i<=id+d && i<arr.size(); i++) {
            if(arr[i] >= arr[id]) break;
            dp[id] = max(dp[id], 1 + helper(i, dp, arr, d));
        }
        
        for(int i=id-1; i>=id-d && i>=0; i--) {
            if(arr[i] >= arr[id]) break;
            dp[id] = max(dp[id], 1 + helper(i, dp, arr, d));
        }
        return dp[id];
    }
    
    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size(), -1);
        for(int i=0; i<arr.size(); i++) {
            helper(i, dp, arr, d);
        }
        return *max_element(dp.begin(), dp.end());
    }
};