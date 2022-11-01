class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> ans(n); for(int i=0; i<n; i++) ans[i] = i;
        for(int ii=0; ii<grid.size(); ii++) {
            vector<int> newans(n, -1);
            for(int i=0; i<n; i++) {
                if(i!=n-1 && grid[ii][i] == grid[ii][i+1] && grid[ii][i] == 1) newans[i+1] = ans[i];
                else if(i!=0 && grid[ii][i] == grid[ii][i-1] && grid[ii][i] == -1) newans[i-1] = ans[i];
            }
            ans = newans;
        }
        vector<int> res(n, -1);
        for(int i=0; i<n; i++) {
            if(ans[i] != -1) res[ans[i]] = i;
        }
        return res;
    }
};