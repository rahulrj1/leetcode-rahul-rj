class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                vector<int> a = {points[i][0], points[i][1]};
                vector<int> b = {points[j][0], points[j][1]};
                
                int slopeSign = (b[1]-a[1])*(b[0]-a[0]);
                
                if(slopeSign <= 0) {
                    bool flag = true;
                    for(vector<int> point: points) {
                        if(point != a && point != b) {
                            if(point[0] >= min(a[0], b[0]) && point[0] <= max(a[0], b[0]) && point[1] >= min(a[1], b[1]) && point[1] <= max(a[1], b[1])) {flag = false; break;}
                        } 
                    }
                    if(flag) res++;
                }
            }
        }
        return res;
    }
};