class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(min(x1, x2) <= xCenter && xCenter <= max(x1, x2) && min(y1, y2) <= yCenter && yCenter <= max(y1, y2) ) return true;
        for(int i=min(x1, x2); i<=max(x1, x2); i++) {
            if((xCenter-i)*(xCenter-i) + (yCenter-y1)*(yCenter-y1) <= radius*radius) return true;
            if((xCenter-i)*(xCenter-i) + (yCenter-y2)*(yCenter-y2) <= radius*radius) return true;
        }
        
        for(int j=min(y1, y2); j<=max(y1, y2); j++) {
            if((xCenter-x1)*(xCenter-x1) + (yCenter-j)*(yCenter-j) <= radius*radius) return true;
            if((xCenter-x2)*(xCenter-x2) + (yCenter-j)*(yCenter-j) <= radius*radius) return true;
        }
        return false;
    }
};