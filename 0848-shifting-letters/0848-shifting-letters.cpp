class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        int shift = 0;
        for(int i=n-1; i>=0; i--) {
            shift += shifts[i]; shift %= 26;
            int curr = shift + (s[i]-'a'); curr %= 26;
            
            s[i] = 'a'+curr;
        }
        return s;
    }
};