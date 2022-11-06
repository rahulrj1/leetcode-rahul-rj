//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    
    string helper(string &s, int id, int k) {
        if(id == s.length() || k == 0) return s;
        string ans = s;
        for(int i=id+1; i<s.length(); i++) {
            if(s[i] > s[id]) {
                swap(s[i], s[id]);
                string temp = helper(s, id+1, k-1);
                if(temp > ans) ans = temp;
                swap(s[i], s[id]);
            }
        }
        ans = max(ans, helper(s, id+1, k));
        return ans;
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        return helper(str, 0, k);
       // code here.
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends