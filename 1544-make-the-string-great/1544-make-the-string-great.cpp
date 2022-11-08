class Solution {
public:
    string makeGood(string str) {
        stack<char> s;
        for(char c: str) {
            if(!s.empty() && s.top() != c && tolower(s.top()) == tolower(c)) s.pop();
            else s.push(c);
        }
        string ans = "";
        while(!s.empty()) ans = s.top() + ans, s.pop();
        return ans;
    }
};