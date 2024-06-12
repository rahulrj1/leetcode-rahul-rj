class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0) continue;
                area += 2 + 4*grid[i][j];
                int top = i == 0 ? 0 : grid[i-1][j];
                int left = j == 0 ? 0 : grid[i][j-1];
                area -= min(grid[i][j], top)*2;
                area -= min(grid[i][j], left)*2;
            }
        }
        return area;
    }
};