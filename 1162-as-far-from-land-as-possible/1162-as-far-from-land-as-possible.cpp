class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int vis[grid.size()][grid[0].size()];
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                vis[i][j] = grid[i][j];
                if(grid[i][j]) q.push({i, j});
            }
        }
        
        int dis = -1;
        const pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                pair<int, int> lCell = q.front(); q.pop();
                for(pair<int, int> d:dir) {
                    int x = lCell.first + d.first, y = lCell.second + d.second;
                    if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && vis[x][y] == 0) {
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            dis++;
        }
        
        return dis == 0 ? -1 : dis;
    }
};