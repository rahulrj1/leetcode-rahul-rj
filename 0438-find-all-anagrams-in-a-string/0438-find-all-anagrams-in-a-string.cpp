class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length() < p.length()) return ans;
        vector<int> freq(26, 0);
        for(int i=0; i<s.length(); i++) {
            if(i<p.length()) {
                freq[s[i]-'a']++;
                freq[p[i]-'a']--;
            }
            else {
                for(int k=0; k<26; k++) {
                    if(freq[k] != 0) break;
                    else if(k==25) ans.push_back(i-p.length());
                }
                freq[s[i]-'a']++;
                freq[s[i-p.length()]-'a']--;
            }
        }
        for(int k=0; k<26; k++) {
            if(freq[k] != 0) break;
            else if(k==25) ans.push_back(s.length()-p.length());
        }
        return ans;
    }
};