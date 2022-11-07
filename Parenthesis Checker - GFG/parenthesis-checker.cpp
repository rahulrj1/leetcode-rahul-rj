//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for(char c: x) {
            if(c == ')') {
                if(s.empty() || s.top() != '(') return false;
                else s.pop();
            }
            else if(c == '}'){
                if(s.empty() || s.top() != '{') return false;
                else s.pop();
            } 
            else if(c == ']'){
                if(s.empty() || s.top() != '[') return false;
                else s.pop();
            } 
            else s.push(c);
        }
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends