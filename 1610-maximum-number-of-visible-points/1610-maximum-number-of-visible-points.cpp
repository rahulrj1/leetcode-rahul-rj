class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> v;
        double pi = acos(-1.0);
        int overlap = 0;
        for(vector<int> &point: points) {
            if(point==location) {overlap++; continue;}
            double ang = atan2(point[1]-location[1], point[0]-location[0])*180.0/pi;
            v.push_back(ang < 0 ? ang + 360.0 : ang);
        }
        sort(v.begin(), v.end());
        int n = v.size();
        for(int i=0; i<n; i++) {
            v.push_back(v[i] + 360.0);
        }
        
        int end = 0, res = 0;
        for(int i=0; i<v.size(); i++) {
            while(end < v.size() && v[end]-v[i] <= angle + 1e-9) end++;
            res = max(res, end-i);
        }
        
        return res + overlap;
    }
};