class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> revmp;
        int j = 0;
        for(int i=0; i<pattern.size(); i++) {
            string word = "";
            while(j<s.length()) {
                if(s[j] == ' ') {j++; break;}
                word += s[j++];
            }
            if(word == "") return false;
            if(mp.find(pattern[i]) == mp.end()) {
                if(revmp.find(word) != revmp.end()) return false;
                mp[pattern[i]] = word;
                revmp[word] = pattern[i];
            }
            else if(mp[pattern[i]] != word) return false;
        }
        if(j != s.length()) return false;
        return true;
    }
};