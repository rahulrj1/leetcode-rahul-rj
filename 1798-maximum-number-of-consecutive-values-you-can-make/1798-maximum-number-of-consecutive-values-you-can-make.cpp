class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int lastVal = 0;
        for(int coin: coins) {
            if(coin > lastVal + 1) return lastVal + 1;
            lastVal += coin;
        }
        return lastVal + 1;
    }
};