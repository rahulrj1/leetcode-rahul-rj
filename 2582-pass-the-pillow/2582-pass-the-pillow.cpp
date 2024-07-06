class Solution {
public:
    int passThePillow(int n, int time) {
        int a = (time-1)/(n-1); // a even means going from left to right
        int b = time%(n-1); if(b == 0) b = n-1; // distance from left/right extreme
        
        return (a&1) ? n - b : 1 + b ;
    }
};