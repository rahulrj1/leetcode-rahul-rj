class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), area = 0;
        vector<int> row(n, 0);
        vector<int> col(n, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > 0) area++;
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        for(int r: row) area += r;
        for(int c: col) area += c;
        return area;
    }
};