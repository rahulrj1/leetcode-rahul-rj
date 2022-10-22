class Solution {
public:
    bool check(unordered_map<char, int> &mp, unordered_map<char, int> &mp1) {
        bool flag = true;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(mp1[it->first] < it->second) {flag = false; break;}
        }
        return flag;
    }
    
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        unordered_map<char, int> mp; for(auto c: t) mp[c]++;
        unordered_map<char, int> mp1;
        int st = 0;
        int ast , alen = 0;
        for(int i=0; i<s.length(); i++) {
            mp1[s[i]]++;
            if(i<t.length()-1) continue;
            while(check(mp, mp1)) {
                if(alen != 0) {
                    if(i-st+1 < alen) alen = i-st+1, ast = st;
                }
                else alen = i-st+1, ast = st;
                mp1[s[st]]--;
                st++;
            }  
        }
        if(alen == 0) return "";
        return s.substr(ast, alen);
    }
};