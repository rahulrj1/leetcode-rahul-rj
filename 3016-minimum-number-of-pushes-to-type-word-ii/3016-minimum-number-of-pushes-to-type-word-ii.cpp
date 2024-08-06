class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for(char &c: word) cnt[c-'a']++;
        
        sort(cnt.rbegin(), cnt.rend());
        int res = 0;
        for(int i=0; i<26; i++) {
            if(i<8) res += cnt[i];
            else if(i<16) res += cnt[i]*2;
            else if(i<24) res += cnt[i]*3;
            else res += cnt[i]*4;
        }
        return res;
    }
};