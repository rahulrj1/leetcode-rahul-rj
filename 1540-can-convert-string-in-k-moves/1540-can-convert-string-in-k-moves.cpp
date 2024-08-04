class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return false;
        vector<int> z(26, 0);
        int quo = k/26, rem = k%26;
        for(int i=0; i<26; i++) {
            z[i] += quo;
            if(i<rem) z[i]++;
        } 
        
        // z[i] means shifing i+1 times
        for(int i=0; i<s.length(); i++) {
            int shift = t[i]-s[i];
            if(shift < 0) shift += 26;
            
            if(shift == 0) continue;
            if(z[shift-1] <= 0) return false;
            z[shift-1]--;
        }
        return true;
    }
};