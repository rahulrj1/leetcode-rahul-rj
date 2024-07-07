class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, full = numBottles, empty = 0;
        
        while(full) {
            res += full;
            empty += full;
            
            full = empty/numExchange;
            empty = empty%numExchange;
        }
        
        return res;
    }
};