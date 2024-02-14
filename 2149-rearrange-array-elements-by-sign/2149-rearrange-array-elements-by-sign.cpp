class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int in = 1, ip = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) res[ip] = nums[i], ip += 2;
            else res[in] = nums[i], in += 2;
        }
        return res;
    }
};