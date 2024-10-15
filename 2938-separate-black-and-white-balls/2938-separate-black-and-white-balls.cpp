class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int black = 0;
        for(char &c: s) {
            if(c == '1') black++;
            else res += 1LL*black;
        }
        return res;
    }
};