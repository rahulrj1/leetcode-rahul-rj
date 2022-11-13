class Solution {
public:
    string findans(string &s, int start, int end) {
        string r = "";
        while(s[start] == ' ') start++;
        while(s[end] == ' ') end--;
        for(int i=start; i<=end; i++) {
            if(s[i]==' ') {
                string ans = findans(s, i+1, end);
                ans += " ";
                ans += r;
                return ans;
            }
            r += s[i];
        }
        return r;
    }
    
    string reverseWords(string s) {
        int start = 0, end = s.length()-1;
        return findans(s, start, end);
    }
};