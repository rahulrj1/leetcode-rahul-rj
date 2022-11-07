//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = pattern.length(), m = str.length();
        bool dp[n+1][m+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                if(i == 0) dp[i][j] = j==0 ? 1 : 0;
                else if(j == 0) dp[i][j] = dp[i-1][j]&(pattern[i-1]=='*');
                else if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') dp[i][j] = dp[i-1][j-1]; 
                else if(pattern[i-1] == '*') dp[i][j] = dp[i-1][j]|dp[i][j-1];
                else dp[i][j] = 0;
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends