class Solution {
public:
    char helper(char c, unordered_map<char, char> &mp) {
        if(mp[c] != c) return helper(mp[c], mp);
        return c;
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, char> mp;
        for(char c = 'a'; c <= 'z'; c++) mp[c] = c;
        for(int i=0; i<s1.length(); i++) {
            char a = helper(s1[i], mp), b = helper(s2[i], mp);
            if(a > b) swap(a, b);
            mp[b] = a;
        }
        for(int i=0; i<baseStr.size(); i++) {
            baseStr[i] = helper(baseStr[i], mp);
        }
        return baseStr;
    }
};