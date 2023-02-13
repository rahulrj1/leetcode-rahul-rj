class Solution {
public:
    int countOdds(int low, int high) {
        if((low&1) && (high&1)) return (high - low + 2)/2;
        else if((low&1)|(high&1)) return (high - low + 1)/2;
        else return (high-low)/2;
    }
};