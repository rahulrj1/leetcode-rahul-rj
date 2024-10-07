class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        for(char &c: s) {
            if(c == 'B') {
                if(!st.empty() && st.top() == 'A') st.pop();
                else st.push(c);
            } else if(c == 'D') {
                if(!st.empty() && st.top() == 'C') st.pop();
                else st.push(c);
            } else {
                st.push(c);
            }
        }
        return st.size();
    }
};