class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int i=0; i<strs[0].length(); i++) {
            string word = "";
            for(string s: strs) word += s[i];
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            if(word != sortedWord) ans++;
        }
        return ans;
    }
};