class Solution {
public:
    void updateArea(double &res, vector<int> &a, vector<int> &b, vector<int> &c, unordered_map<int, unordered_set<int>> &yforx) {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        int x3 = c[0], y3 = c[1];

        // check if they form 90 degree at (x2, y2)
        if((x1-x2)*(x3-x2) + (y1-y2)*(y3-y2) != 0) return;
        int x4 = x1 + x3 - x2, y4 = y1 + y3 - y2;
        if(yforx[x4].find(y4) == yforx[x4].end()) return;

        double area = abs((x3-x2)*(y1-y2) - (x1-x2)*(y3-y2));
        res = min(res, area);
    }
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        double res = INT_MAX;
        unordered_map<int, unordered_set<int>> yforx; // all y's for x
        for(vector<int> point: points) yforx[point[0]].insert(point[1]);
            
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                for(int k=j+1; k<points.size(); k++) {
                    updateArea(res, points[i], points[j], points[k], yforx);
                    updateArea(res, points[j], points[i], points[k], yforx);
                    updateArea(res, points[j], points[k], points[i], yforx);
                }
            }
        }
        if(res == INT_MAX) res = 0;
        return res;
    }
};