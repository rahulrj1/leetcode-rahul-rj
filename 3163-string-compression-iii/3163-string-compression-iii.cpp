class Solution {
public:
    string compressedString(string word) {
        string res = "";
        char pr = word[0], cnt = 0;
        for(char c: word) {
            if(c != pr || cnt == 9) {
                res += to_string(cnt) + pr;
                cnt = 1;
            }
            else cnt++;
            pr = c;
        }
        res += to_string(cnt) + pr;
        return res;
    }
};