//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int ans = 1;
      unordered_set<int> s;
      for(int i=0; i<N; i++) {
          s.insert(arr[i]);
      }
      for(int i=0; i<N; i++) {
          if(s.count(arr[i]-1) == 0) {
              int cnt = 0, curr = arr[i];
              while(s.count(curr) == 1) cnt++, curr++;
              ans = max(ans, cnt);
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends