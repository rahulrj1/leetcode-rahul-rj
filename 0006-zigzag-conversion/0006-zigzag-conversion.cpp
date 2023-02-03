class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string str[numRows]; for(int i=0; i<numRows; i++) str[i] = "";
        int row = 0, dir; // dir 1 means up
        
        for(int i=0; i<s.length(); i++) {
            str[row] += s[i];
            if(row==0) dir = 0;
            else if(row==numRows-1) dir = 1;
            
            if(dir==0) row++;
            else row--;
        }
        
        string ans = "";
        for(int i=0; i<numRows; i++) ans += str[i];
        return ans;
    }
};