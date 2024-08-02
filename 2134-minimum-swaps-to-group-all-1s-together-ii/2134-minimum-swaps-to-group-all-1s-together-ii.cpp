class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int numOne = 0, numZero = 0;
        for(int num: nums) if(num == 1) numOne++;
        int r, res = 1e6, n = nums.size();
        for(r=0; r<numOne; r++) if(nums[r] == 0) numZero++; 
        res = min(res, numZero);
        while(r<n) {
            if(nums[r] == 0) numZero++;
            if(nums[r-numOne] == 0) numZero--;
            res = min(res, numZero);
            r++;
        }
        
        int l = r-numOne;
        while(l<n) {
            if(nums[l] == 0) numZero--;
            if(nums[l+numOne-n] == 0) numZero++;
            
            res = min(res, numZero);
            l++;
        }
        return res;
    }
};