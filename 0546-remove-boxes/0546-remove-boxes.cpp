class Solution {
public:
    int dp[101][101][101];
    
    int helper(vector<int> &boxes, int l, int r, int streak) {
        if(l > r) return 0;
        if(dp[l][r][streak] != -1) return dp[l][r][streak];
        
        int ans = (streak+1)*(streak+1) + helper(boxes, l+1, r, 0);
        for(int i=l+1; i<=r; i++) {
            if(boxes[i] == boxes[l]) {
                ans = max(ans, helper(boxes, l+1, i-1, 0) + helper(boxes, i, r, streak+1));
            }
        }
        return dp[l][r][streak] = ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return helper(boxes, 0, boxes.size()-1, 0);
    }
};