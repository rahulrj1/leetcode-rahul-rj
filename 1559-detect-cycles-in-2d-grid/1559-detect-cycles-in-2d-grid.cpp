class Solution {
public:
    bool hasCycle(vector<vector<char>> &grid, int x, int y, int px, int py, vector<vector<bool>> &vis, char &c) {
        vis[x][y] = true;
        int delx[] = {0, 0, 1, -1}, dely[] = {1, -1, 0, 0};
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<4; i++) {
            int dx = delx[i], dy = dely[i];
            if(x+dx == px && y+dy == py) continue;
            if(x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && grid[x+dx][y+dy] == c) {
                if(vis[x+dx][y+dy]) return true;
                else if(hasCycle(grid, x+dx, y+dy, x, y, vis, c)) return true;
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool> > vis(n, vector<bool> (m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && hasCycle(grid, i, j, -1,-1, vis, grid[i][j])) return true;
            }
        }
        return false;
    }
};