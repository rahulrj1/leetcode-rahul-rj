class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(col, vector<int> (col, 0));
        dp[0][col-1] = grid[0][0] + grid[0][col-1];
        
        int z[3] = {-1, 0, 1}, res;
        for(int r=1; r<row; r++) {
            res = INT_MIN;
            vector<vector<int>> ndp(col, vector<int> (col, 0));
            for(int i=0; i<=r && i<col; i++) {
                for(int j=col-1; j>=(col-1-r) && j>=0; j--) {
                    for(int k=0; k<3; k++) {
                        for(int l=0; l<3; l++) {
                            if(i+z[k] < 0 || j+z[l] < 0 || i+z[k] >= col || j+z[l] >= col) continue;
                            int temp = dp[i+z[k]][j+z[l]] + grid[r][i] + grid[r][j];
                            if(i == j) temp -= grid[r][i];
                            
                            ndp[i][j] = max(temp, ndp[i][j]);
                        }
                    }
                    res = max(res, ndp[i][j]);
                }
            }
            dp = ndp;
        }
        return res;
    }
};