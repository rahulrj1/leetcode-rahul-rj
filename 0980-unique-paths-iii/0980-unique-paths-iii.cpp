class Solution {
public:
    int empty = 1, ans = 0;
    
    void dfs(vector<vector<int>> &grid, int x, int y, int cnt) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return;
        
        if(grid[x][y] == 2) {
            if(empty == cnt) ans++;
            return;
        }
        
        grid[x][y] = -1;
        
        dfs(grid, x+1, y, cnt+1);
        dfs(grid, x-1, y, cnt+1);
        dfs(grid, x, y+1, cnt+1);
        dfs(grid, x, y-1, cnt+1);
        
        grid[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx, sy;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) sx = i, sy = j;
                else if(grid[i][j] == 0) empty++;
            }
        }
        
        dfs(grid, sx, sy, 0);
        
        return ans;
    }
};