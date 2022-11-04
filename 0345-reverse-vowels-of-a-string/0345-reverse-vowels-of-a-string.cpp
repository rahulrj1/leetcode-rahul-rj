class Solution {
public:
    bool notVowel(char c) {
        string s = "aeiouAEIOU";
        for(auto ch: s) if(c == ch) return false;
        return true;
    }
    
    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        while(i<j) {
            while(i<j && notVowel(s[i])) i++;
            while(i<j && notVowel(s[j])) j--;
            swap(s[i], s[j]);
            i++, j--;
        }
        return s;
    }
};