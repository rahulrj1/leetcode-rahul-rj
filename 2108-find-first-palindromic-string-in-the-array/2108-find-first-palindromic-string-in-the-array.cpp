class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s: words) {
            int n = s.length(); bool isPal = true;
            for(int i=0; i<n/2; i++) if(s[i] != s[n-1-i]) isPal = false;
            if(isPal) return s;
        }
        return "";
    }
};