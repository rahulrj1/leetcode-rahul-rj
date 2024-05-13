class Solution {
public:
    void toggle(vector<vector<int>> &grid, char c, int n) {
        if(c == 'r') for(int j=0; j<grid[0].size(); j++) grid[n][j] = grid[n][j] == 0 ? 1 : 0;
        else for(int i=0; i<grid.size(); i++) grid[i][n] = grid[i][n] == 0 ? 1 : 0;
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) if(grid[i][0] == 0) toggle(grid, 'r', i);
        for(int j=1; j<grid[0].size(); j++) {
            int one = 0, zero = 0;
            for(int i=0; i<grid.size(); i++) {
                if(grid[i][j] == 0) zero++;
                else one++;
            }
            if(zero > one) toggle(grid, 'c', j);
        }
        
        int ans = 0, m = grid[0].size();
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<m; j++) {
                ans += grid[i][j]<<(m-1-j);
            }
        }
        return ans;
    }
};