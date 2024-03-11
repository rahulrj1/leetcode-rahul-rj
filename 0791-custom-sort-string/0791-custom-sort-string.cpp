class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26, 0);
        for(char c: s) cnt[c-'a']++;
        
        string res = "";
        for(char c: order) {
            while(cnt[c-'a']--) res += c;
        }
        for(int i=0; i<26; i++) {
            while(cnt[i]-- > 0) res += ('a'+i);
        }
        return res;
    }
};