class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length(), cap = 0;
        for(char c: word) if(c <= 'Z' && c >= 'A') cap++;
        return cap == 0 || cap == n || (cap == 1 && word[0] <= 'Z' && word[0] >= 'A');
    }
};