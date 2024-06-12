class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y1_minus_y0 = coordinates[1][1] - coordinates[0][1];
        int x1_minus_x0 = coordinates[1][0] - coordinates[0][0];
            
        for(int i=2; i<coordinates.size(); i++) {
            int yi_minus_y0 = coordinates[i][1] - coordinates[0][1];
            int xi_minus_x0 = coordinates[i][0] - coordinates[0][0];
            
            // yi_minus_y0/xi_minus_x0 = y1_minus_y0/x1_minus_x0
            if(yi_minus_y0*x1_minus_x0 != y1_minus_y0*xi_minus_x0) return false;
        }
        return true;
    }
};