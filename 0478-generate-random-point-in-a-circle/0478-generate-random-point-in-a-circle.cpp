class Solution {
public:
    double r, x, y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double ang, rad;
        ang = (double)rand()/RAND_MAX * 2 * M_PI;
        rad = sqrt((double)rand()/RAND_MAX) * r;
        
        return {x + rad*cos(ang), y + rad*sin(ang)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */