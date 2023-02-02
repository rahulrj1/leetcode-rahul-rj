class Solution {
public:
    bool notSorted(string &a, string &b, vector<int> &num) {
        for(int i=0; i<a.length(); i++) {
            if(i == b.length()) return true; 
            if(num[a[i]-'a'] > num[b[i]-'a']) return true;
            else if(num[a[i]-'a'] < num[b[i]-'a']) return false;
        }
        return false;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> num(26);
        for(int i=0; i<order.size(); i++) num[order[i]-'a'] = i;
        for(int i=1; i<words.size(); i++) {
            string a = words[i-1], b = words[i];
            if(notSorted(a, b, num)) return false;
        }
        return true;
    }
};