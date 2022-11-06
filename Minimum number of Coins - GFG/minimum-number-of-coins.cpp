//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int dp[N+1][11];
        for(int i=0; i<=N; i++) {
            for(int j=0; j<=10; j++) {
                if(i == 0) dp[i][j] = 0;
                else if(j == 0) dp[i][j] = 1e9;
                else if(arr[j-1] <= i) {
                    dp[i][j] = min(dp[i][j-1], 1 + dp[i-arr[j-1]][j]);
                }
                else dp[i][j] = dp[i][j-1];
            }
        }
        vector<int> ans;
        int i = N, j = 10;
        int cnt = dp[N][10];
        while(i != 0) {
            if(dp[i][j] == dp[i][j-1]) j--;
            else {
                ans.push_back(arr[j-1]);
                i -= arr[j-1];
                cnt--;
            }
            if(cnt == 0) break;
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends