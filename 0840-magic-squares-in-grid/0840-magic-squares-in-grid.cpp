class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int row = 0; row + 2 < m; row++) {
            for(int col = 0; col + 2 < n; col++) {
                if(isMagicSquare(grid, row, col)) ans++;
            }
        }
        return ans;
    }
    
    bool isMagicSquare(vector<vector<int>> &grid, int row, int col) {
        vector<bool> seen(10, false);
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                int num = grid[row+i][col+j];
                if(num < 1 || num > 9) return false;
                if(seen[num]) return false;
                seen[num] = true;
            }
        }
        
        int d1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int d2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if(d1 != d2) return false;
        
        // Check if all row sums are the same as the diagonal sums
        int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int row2 = grid[row + 1][col] + grid[row + 1][col + 1] +
                   grid[row + 1][col + 2];
        int row3 = grid[row + 2][col] + grid[row + 2][col + 1] +
                   grid[row + 2][col + 2];

        if (!(row1 == d1 && row2 == d1 && row3 == d1)) {
            return false;
        }

        // Check if all column sums are the same as the diagonal sums
        int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int col2 = grid[row][col + 1] + grid[row + 1][col + 1] +
                   grid[row + 2][col + 1];
        int col3 = grid[row][col + 2] + grid[row + 1][col + 2] +
                   grid[row + 2][col + 2];

        if (!(col1 == d1 && col2 == d1 && col3 == d1)) {
            return false;
        }

        return true;
    }
};