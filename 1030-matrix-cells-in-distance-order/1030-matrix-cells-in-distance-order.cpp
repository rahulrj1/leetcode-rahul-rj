class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        vector<vector<bool>> vis(rows, vector<bool> (cols, false));
        queue<vector<int>> q;
        q.push({rCenter, cCenter}); vis[rCenter][cCenter] = true;
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                vector<int> temp = q.front(); q.pop(); 
                res.push_back(temp);
                int r = temp[0], c = temp[1];
                if(r+1 < rows && !vis[r+1][c]) q.push({r+1, c}), vis[r+1][c] = true;
                if(r-1 >= 0 && !vis[r-1][c]) q.push({r-1, c}), vis[r-1][c] = true;
                if(c+1 < cols && !vis[r][c+1]) q.push({r, c+1}), vis[r][c+1] = true;
                if(c-1 >= 0 && !vis[r][c-1]) q.push({r, c-1}), vis[r][c-1] = true;
            }
        }
        return res;
    }
};