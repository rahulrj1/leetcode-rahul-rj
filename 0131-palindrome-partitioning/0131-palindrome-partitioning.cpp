class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    void findans(vector<vector<string>> &ans, vector<string> &temp, string s, int l) {
        if(l==s.length()) {
            ans.push_back(temp);
            return;
        }
        for(int i=l; i<s.length(); i++) {
            if(isPalindrome(s, l, i)) {
                temp.push_back(s.substr(l, i-l+1));
                findans(ans, temp, s, i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        findans(ans, temp, s, 0);
        return ans;
    }
};