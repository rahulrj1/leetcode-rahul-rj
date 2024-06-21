class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        // |x1 - x2| + |y1 - y2| = max{x1 - x2 + y1 - y2, x1 - x2 + y2 - y1, x2 - x1 + y1 - y2, x2 - x1 + y2 - y1} = max{e1 + e2, e3 + e4}
        
        int f1 = INT_MIN, f2 = INT_MIN, f3 = INT_MIN, f4 = INT_MIN;
        int s1 = INT_MIN, s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
        
        for(vector<int> &point: points) {
            int x = point[0], y = point[1];
            if(x+y > f1) s1 = f1, f1 = x+y; else if(x+y > s1) s1 = x+y;
            if(-x-y > f2) s2 = f2, f2 = -x-y; else if(-x-y > s2) s2 = -x-y;
            if(-x+y > f3) s3 = f3, f3 = -x+y; else if(-x+y > s3) s3 = -x+y;
            if(x-y > f4) s4 = f4, f4 = x-y; else if(x-y > s4) s4 = x-y;
        }
        
        int res = INT_MAX;
        for(vector<int> &point: points) {
            int x = point[0], y = point[1];
            int e1 = f1, e2 = f2, e3 = f3, e4 = f4;
            if(x+y == f1) e1 = s1;
            if(-x-y == f2) e2 = s2;
            if(-x+y == f3) e3 = s3;
            if(x-y == f4) e4 = s4;
            
            int tempRes = max(e1+e2, e3+e4); // result on excluding the current point
            res = min(res, tempRes);
        }
        
        return res;
    }
};