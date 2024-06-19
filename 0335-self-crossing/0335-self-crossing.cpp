class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        for(int i=3; i<n; i++) {
            // if ith line crosses (i-3)th line
            if(x[i] >= x[i-2] && x[i-3] >= x[i-1]) return true;
            
            // if ith line crosses (i-4)th line
            if(i >= 4 && x[i-1] == x[i-3] && x[i-4] + x[i] >= x[i-2]) return true;
            
            // if ith line crosses (i-4)th line
            if(i >= 5 && x[i-2] <= x[i-4] + x[i] && x[i-4] <= x[i-2] && x[i-3] <= x[i-1] + x[i-5] && x[i-1] <= x[i-3]) return true;
            
        }
        return false;
    }
};