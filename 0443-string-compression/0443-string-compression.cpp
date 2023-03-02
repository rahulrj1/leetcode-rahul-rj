class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0, cnt = 1;
        char pr = chars[0];
        int t = 0;
        for(int i=1; i<chars.size(); i++) {
            if(chars[i] == pr) cnt++;
            else {
                chars[t++] = pr;
                string tmp = to_string(cnt);
                if(cnt != 1) for(auto ch: tmp) chars[t++] = ch;
                cnt = 1, pr = chars[i];
            }
        }
        chars[t++] = pr;
        string tmp = to_string(cnt); 
        if(cnt != 1) for(auto ch: tmp) chars[t++] = ch;
        return t;
    }
};