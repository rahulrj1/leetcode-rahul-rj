class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> y = grid, z = grid;
        int ans = 0;
        for(int i=1; i<n; i++) {
            for(int j=1; j<m-1; j++) {
                if(y[i][j] != 0) y[i][j] = 1 + min({y[i-1][j-1], y[i-1][j], y[i-1][j+1]});
                ans += max(y[i][j] - 1, 0);
            }
        }
        for(int i=n-2; i>=0; i--) {
            for(int j=1; j<m-1; j++) {
                if(z[i][j] != 0) z[i][j] = 1 + min({z[i+1][j-1], z[i+1][j], z[i+1][j+1]});
                ans += max(z[i][j] - 1, 0);
            }
        }
        return ans;
    }
};