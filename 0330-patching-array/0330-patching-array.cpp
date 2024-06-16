class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long highestPossibleNum = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if(highestPossibleNum >= n) return res;
            if(num > highestPossibleNum + 1) {
                // insert highestPossibleNum + 1
                highestPossibleNum *= 2;
                highestPossibleNum++;
                res++;
                i--;
            }
            else highestPossibleNum += num;
        }
        while(highestPossibleNum < n) {
            highestPossibleNum *= 2;
            highestPossibleNum++;
            res++;
        }
        return res;
    }
};