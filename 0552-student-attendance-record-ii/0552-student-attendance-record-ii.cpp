class Solution {
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> memo;
public:
    int helper(int n, int absentDays, int lastConsLate) {
        // base case
        if(absentDays >= 2 || lastConsLate >= 3) return 0;
        if(n == 0) return 1;
        
        if(memo[n][absentDays][lastConsLate] != -1) return memo[n][absentDays][lastConsLate];
        
        // P
        int cnt = helper(n-1, absentDays, 0);
        
        // A
        cnt = (cnt + helper(n-1, absentDays+1, 0)) % mod;
        
        // L
        cnt = (cnt + helper(n-1, absentDays, lastConsLate+1)) % mod;
        
        return memo[n][absentDays][lastConsLate] = cnt;
    }
    
    int checkRecord(int n) {
        memo = vector<vector<vector<int>>> (n+1, vector<vector<int>> (2, vector<int> (3, -1)));
        return helper(n, 0, 0);
    }
};