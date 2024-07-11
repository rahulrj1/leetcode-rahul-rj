class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char c: s) {
            if(c != ')') st.push(c);
            else {
                stack<char> temp;
                while(st.top() != '(') temp.push(st.top()), st.pop();
                st.pop();
                stack<char> t2;
                while(!temp.empty()) t2.push(temp.top()), temp.pop();
                while(!t2.empty()) st.push(t2.top()), t2.pop();
            }
        }
        string ans = "";
        while(!st.empty()) ans += st.top(), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};