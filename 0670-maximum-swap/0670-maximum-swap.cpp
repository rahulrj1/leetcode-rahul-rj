class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string res = s;
        for(int i=0; i<s.length(); i++) {
            for(int j=i+1; j<s.length(); j++) {
                swap(s[i], s[j]);
                res = max(res, s);
                swap(s[i], s[j]);
            }
        }
        return stoi(res);
    }
};