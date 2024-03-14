class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), sum = 0, res = 0;
        vector<int> cntSum(n+1, 0); cntSum[0]++;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) sum++;
            if(sum - goal >= 0) res += cntSum[sum - goal];
            cntSum[sum]++;
        }
        return res;
    }
};