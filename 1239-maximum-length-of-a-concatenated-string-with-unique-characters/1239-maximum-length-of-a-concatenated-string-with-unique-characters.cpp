class Solution {
public:
    void helper(vector<string> &arr, int start, unordered_set<char> &st, int &ans) {
        int tempans = st.size();
        if(start == arr.size()) {ans = max(ans, tempans); return;}
        
        // either we can take the start word or leave it
        vector<bool> isPres(26, false);
        for(int j=0; j<arr[start].length(); j++) {
            char c = arr[start][j];
            if(isPres[c-'a'] == true) break; isPres[c-'a'] = true; //check if no char repeat
            if(st.find(c) != st.end()) break;
            else if(j==arr[start].length()-1) {
                for(auto ch: arr[start]) st.insert(ch);
                helper(arr, start+1, st, ans);
                for(auto ch: arr[start]) st.erase(ch);
            }
        }
        helper(arr, start+1, st, ans);
        
    }
    
    int maxLength(vector<string>& arr) {
        unordered_set<char> st;
        int ans = 0;
        helper(arr, 0, st, ans);
        return ans;
    }
};