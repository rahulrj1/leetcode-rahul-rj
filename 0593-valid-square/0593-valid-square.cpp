class Solution {
public:
    int find_diff(vector<int> &a, vector<int> &b) {
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> s(6);
        s[0] = find_diff(p1, p2);
        s[1] = find_diff(p1, p3);
        s[2] = find_diff(p1, p4);
        s[3] = find_diff(p2, p3);
        s[4] = find_diff(p2, p4);
        s[5] = find_diff(p3, p4);
        sort(s.begin(), s.end());
        
        return s[0] != 0 && s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5] && s[5] == 2*s[0];
    }
};