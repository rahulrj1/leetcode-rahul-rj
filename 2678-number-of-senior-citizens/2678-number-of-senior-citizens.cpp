class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string &d: details) res += stoi(d.substr(11, 2)) > 60;
        return res;
    }
};