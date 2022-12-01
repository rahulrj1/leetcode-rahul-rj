class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        if(n&1) return false;
        
        int cnt = 0;
        for(int i=0; i<n; i++) 
            for(char c: "AEIOUaeiou") 
                if(s[i] == c) cnt += i<n/2 ? 1 : -1;
        
        return cnt == 0;
    }
};