class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0;
        for(char c: to_string(n)) prod *= (c-'0'), sum += (c-'0');
        return prod - sum;
    }
};