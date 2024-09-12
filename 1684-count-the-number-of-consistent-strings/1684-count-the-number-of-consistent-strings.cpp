class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        vector<int> cnt(26, false);
        for(char &c: allowed) cnt[c-'a'] = true;
        
        for(string &word: words) {
            bool consistent = true;
            for(char &c: word) {
                if(cnt[c-'a'] == false) {
                    consistent = false;
                    break;
                }
            }
            if(consistent) res++;
        }
        
        return res;
    }
};