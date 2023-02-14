class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1, j=b.length()-1;
        int carry = 0;
        string ans = "";
        while(i>=0 || j>=0) {
            int n1 = i>=0 ? a[i--]-'0' : 0;
            int n2 = j>=0 ? b[j--]-'0' : 0;
            
            int sum = n1 + n2 + carry;
            if(sum == 3) ans += "1", carry = 1;
            else if(sum == 2) ans += "0", carry = 1;
            else if(sum == 1) ans += "1", carry = 0;
            else ans += "0", carry = 0;
        }
        if(carry) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};