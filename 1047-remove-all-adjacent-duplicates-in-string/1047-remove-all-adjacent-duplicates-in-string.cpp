class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto c: s) {
            if(st.empty() || st.top() != c) st.push(c);
            else st.pop();
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};