class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int gs = grid.size();
        vector<vector<int>> bigGrid(gs*3, vector<int> (gs*3, 1));
        
        for(int i=0; i<gs; i++) {
            for(int j=0; j<gs; j++) {
                int r = i*3, c = j*3;
                
                if(grid[i][j] == '\\') bigGrid[r][c] = 0, bigGrid[r+1][c+1] = 0, bigGrid[r+2][c+2] = 0;
                if(grid[i][j] == '/') bigGrid[r+2][c] = 0, bigGrid[r+1][c+1] = 0, bigGrid[r][c+2] = 0;
            }
        }
        
        int res = 0;
        for(int i=0; i<gs*3; i++) {
            for(int j=0; j<gs*3; j++) {
                if(bigGrid[i][j] == 1) {
                    mark_island(bigGrid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void mark_island(vector<vector<int>> &grid, int x, int y) {
        grid[x][y] = 0;
        int a[] = {-1, 0, 1, 0};
        int b[] = {0, 1, 0, -1};
        for(int t=0; t<4; t++) if(x+a[t]>=0 && x+a[t]<grid.size() && y+b[t]>=0 && y+b[t]<grid[0].size() && grid[x+a[t]][y+b[t]] == 1) mark_island(grid, x+a[t], y+b[t]);
    }
};