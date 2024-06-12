class Solution {
public:
    int findTime(vector<int> &a, vector<int> &b) {
        int del_x = abs(a[0] - b[0]);
        int del_y = abs(a[1] - b[1]);
        return max(del_x, del_y);
    }
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i=1; i<points.size(); i++) {
            time += findTime(points[i-1], points[i]);
        }
        return time;
    }
};