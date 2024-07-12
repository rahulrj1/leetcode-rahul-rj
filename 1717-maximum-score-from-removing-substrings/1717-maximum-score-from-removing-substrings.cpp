class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string st = "";
        char fir = 'a', sec = 'b';
        if(y > x) fir = 'b', sec = 'a';
        int m = min(x, y), M = max(x, y);
        for(char &c: s) {
            if(c == sec) {
                if(st.size() > 0 && st.back() == fir) st.pop_back(), res += M;
                else st.push_back(c);
            }
            else st.push_back(c);
        }
        string r = st; st = "";
        for(char &c: r) {
            if(c == fir) {
                if(st.size() > 0 && st.back() == sec) st.pop_back(), res += m;
                else st.push_back(c);
            }
            else st.push_back(c);
        }
        return res;
    }
};