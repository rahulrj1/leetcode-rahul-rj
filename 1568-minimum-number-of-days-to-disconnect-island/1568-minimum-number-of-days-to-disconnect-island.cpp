class Solution {
public:
    void mark_island(vector<vector<int>> &grid, int x, int y) {
        grid[x][y] = 0;
        int a[] = {-1, 0, 1, 0};
        int b[] = {0, 1, 0, -1};
        for(int t=0; t<4; t++) if(x+a[t]>=0 && x+a[t]<grid.size() && y+b[t]>=0 && y+b[t]<grid[0].size() && grid[x+a[t]][y+b[t]] == 1) mark_island(grid, x+a[t], y+b[t]);
    }
    
    int numberOfIslands(vector<vector<int>> grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    mark_island(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int islandCnt = numberOfIslands(grid);
        if(islandCnt != 1) return 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0) continue;
                
                grid[i][j] = 0;
                int newIslandCnt = numberOfIslands(grid);
                if(newIslandCnt != 1) return 1;
                grid[i][j] = 1;
            }
        }
        
        return 2;
    }
};