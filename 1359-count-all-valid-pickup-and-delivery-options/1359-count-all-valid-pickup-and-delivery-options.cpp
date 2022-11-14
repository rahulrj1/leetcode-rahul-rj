vector<int> dp;
const int mod = 1e9 + 7; 

class Solution {
public:
    long long comb(int n, int r) {
        long long ans = 1;
        int j=r, k=n-r;
        for(int i=n; i>=1; i--) {
            ans *= (long long)i;
            while((ans % j == 0) && j>1) ans /= j--;
            while((ans % k == 0) && k>1) ans /= k--;
        }
        return ans;
    }
    
    void createDP() {
        dp.resize(501); dp[1] = 1;
        for(int i=2; i<=500; i++) {
            long long z = 1LL*dp[i-1]*comb(2*i, 2);
            dp[i] = (z % mod);
        }
    }
    
    int countOrders(int n) {
        // (2*n C 2) * dp[n-1] 
        if(dp.size() == 0) createDP();
        return dp[n];
    }
};