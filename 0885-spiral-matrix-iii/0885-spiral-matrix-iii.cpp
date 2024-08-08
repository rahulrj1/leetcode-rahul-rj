class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        vector<vector<int> > dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        int dirIdx = 0, step = 1;
        int r = rStart, c = cStart;
        while(res.size() < rows*cols) {
            for(int i=0; i<2; i++) {
                for(int j=0; j<step; j++) {
                    if(r >= 0 && r < rows && c >= 0 && c < cols) res.push_back({r, c});
                    
                    r += dir[dirIdx][0];
                    c += dir[dirIdx][1];
                }
                dirIdx = (dirIdx + 1)%4;
            }
            step++;
        }
        return res;
    }
};