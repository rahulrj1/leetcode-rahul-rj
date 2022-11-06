//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string> s(B.begin(), B.end());
        int n = A.length();
        bool dp[n];
        memset(dp, false, sizeof(dp));
        dp[0] = false;
        for(int i=0; i<n; i++) {
            if(s.find(A.substr(0, i+1)) != s.end()) dp[i] = true;
            else {
                for(int j=0; j<i; j++) {
                    if(dp[j] && s.find(A.substr(j+1, i-j)) != s.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends