class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        
        int res = 0;
        for(int i=0; i<points.size(); i++) {
            int maxY = -1e9 - 1;
            for(int j=i+1; j<points.size(); j++) {
                if(points[i][1] >= points[j][1]) {
                    if(maxY < points[j][1]) res++;
                    maxY = max(maxY, points[j][1]);
                }
            }
        }
        return res;
    }
};