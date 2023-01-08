class Solution {
public:
    bool doesLie(vector<vector<int>> &points, int k, int i, int j) {
        return (points[j][0]-points[i][0])*(points[k][1]-points[i][1]) == (points[j][1]-points[i][1])*(points[k][0]-points[i][0]);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                int tempans = 2;
                for(int k=j+1; k<points.size(); k++) {
                    // does k lie on line formed by i and j
                    if(doesLie(points, k, i, j)) tempans++;
                }    
                ans = max(ans, tempans);
            }
        }
        return ans;
    }
};