class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int m = 1e9 + 7;
        int n = locations.size();
        vector<vector<long> > dp(fuel+1, vector<long> (n, 0));
        dp[0][start] = 1;
        
        for(int f=1; f<=fuel; f++) {
            for(int i=0; i<n; i++) {
                dp[f][i] = 0;
                
                for(int j=0; j<n; j++) {
                    if(i == j) continue;
                    
                    if(f-abs(locations[i]-locations[j]) >= 0) {
                        dp[f][i] += 1L*dp[f-abs(locations[i]-locations[j])][j];
                        dp[f][i] %= m;
                    }    
                }
            }
        }
        
        // for(int i=0; i<=fuel; i++) {
        //     for(int j=0; j<n; j++) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        long res = 0;
        for(int i=0; i<=fuel; i++) {
            res += 1L*dp[i][finish];
            res %= m;
        }
        
        return res;
    }
};