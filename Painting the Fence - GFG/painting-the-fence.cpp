//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        if(n == 1) return k;
        const int mod = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long> (2));
        dp[1] = {k, k*(k-1)}; // {same, different}
        for(int i=2; i<n; i++) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0] + dp[i-1][1])*(k-1) % mod;
        }
        return (dp[n-1][0] + dp[n-1][1]) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends