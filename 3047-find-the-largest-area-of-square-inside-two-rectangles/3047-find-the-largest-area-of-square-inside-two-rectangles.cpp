class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long res = 0;
        for(int i=0; i<bottomLeft.size(); i++) {
            for(int j=i+1; j<bottomLeft.size(); j++) {
                int x0l = bottomLeft[i][0], x0r = topRight[i][0];
                int y0b = bottomLeft[i][1], y0t = topRight[i][1];
                int x1l = bottomLeft[j][0], x1r = topRight[j][0];
                int y1b = bottomLeft[j][1], y1t = topRight[j][1];
                
                long long width = min(x0r, x1r) - max(x0l, x1l);
                long long height = min(y0t, y1t) - max(y0b, y1b);
                long long side = min(height, width);
                if(side < 0) continue;
                res = max(res, side*side);
            }
        }
        return res;
    }
};