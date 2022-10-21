class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;
        for(auto it = mp.begin(); it != mp.end(); it++) if(it->second != mp[s[0]]) return false;
        return true;
    }
};