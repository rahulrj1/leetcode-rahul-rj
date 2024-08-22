class Solution {
public:
    int findComplement(int num) {
        int n = num;
        int res = 0, i = 0;
        while(n > 0) {
            if(!(n&1)) res = res|(1<<i);  // add 1
            
            n = (n>>1);
            i++;
        }
        return res;
    }
};