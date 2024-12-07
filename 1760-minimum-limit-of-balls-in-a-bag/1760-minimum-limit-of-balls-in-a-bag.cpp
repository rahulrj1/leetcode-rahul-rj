class Solution {
public:
   bool isPoss(int m, vector<int> &nums, int z) {
       int ops = 0;
       for(int &num: nums) ops += (num-1)/m;
       return ops <= z;
   } 
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, h = 1e9, res;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(isPoss(m, nums, maxOperations)) {
                res = m;
                h = m-1;
            } 
            else l = m+1;
        }
        return res;
    }
};