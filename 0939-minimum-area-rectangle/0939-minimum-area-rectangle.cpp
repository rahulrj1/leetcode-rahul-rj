class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> yforx; // set of y for each x
        for(vector<int> point: points) yforx[point[0]].insert(point[1]);
        
        int res = INT_MAX;
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                vector<int> x = points[i];
                vector<int> y = points[j];
                if(x[0] == y[0] || x[1] == y[1]) continue;
                if(yforx[y[0]].find(x[1]) == yforx[y[0]].end() || yforx[x[0]].find(y[1]) == yforx[x[0]].end()) continue;
                int area = abs((x[0]-y[0])*(x[1]-y[1]));
                res = min(res, area);
            }
        }
        if(res == INT_MAX) res = 0;
        return res;
    }
};