class Solution {
public:
    unordered_set<int> squares;
    
    Solution() {
        long i = 0;
        while(i*i <= INT_MAX) {
            squares.insert(i*i);
            i++;
        }
    }
    
    bool judgeSquareSum(int c) {
        long i = 0;
        while(i*i <= INT_MAX) {
            if(c - i*i >= 0 && squares.find(c - i*i) != squares.end()) return true;
            else if(c - i*i < 0) return false;
            i++;
        }
        return false;
    }
};