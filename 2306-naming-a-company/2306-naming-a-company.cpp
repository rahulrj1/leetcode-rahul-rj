class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        
        unordered_set<string> z[26];
        for(string &s: ideas) z[s[0]-'a'].insert(s.substr(1));
        
        for(int i=0; i<25; i++) {
            for(int j=i+1; j<26; j++) {
                int numMut = 0;
                for(auto& s: z[i]) if(z[j].count(s)) numMut++;
                ans += 2LL*(z[i].size() - numMut)*(z[j].size() - numMut);
            }
        }
        
        return ans;
    }
};