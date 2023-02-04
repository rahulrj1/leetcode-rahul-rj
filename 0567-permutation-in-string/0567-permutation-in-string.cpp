class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(auto c: s1) freq[c-'a']--;
        for(int i=0; i<s2.length(); i++) {
            if(i<s1.length()) freq[s2[i]-'a']++;
            else freq[s2[i]-'a']++, freq[s2[i-s1.length()]-'a']--;
            
            for(int j=0; j<26; j++) {
                if(freq[j]) break;
                else if(j==25) return true;
            }
        }
        return false;
    }
};