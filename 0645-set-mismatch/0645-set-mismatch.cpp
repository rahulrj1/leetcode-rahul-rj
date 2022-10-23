class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long sum = 0, sq_sum = 0;
        for(int n: nums) sum += (long long)n, sq_sum += (long long)n*n;
        
        int n = nums.size();
        int k1_minus_k2 = sum - (long long)n*(n+1)/2; // k1 - k2
        int k1_sq_minus_k2_sq = sq_sum - (long long)n*(n + 1)*(2*n + 1)/6; // k1^2 - k2^2
        int k1_plus_k2 = k1_sq_minus_k2_sq/k1_minus_k2; // k1 + k2
        
        return {(k1_minus_k2 + k1_plus_k2)/2, (k1_plus_k2 - k1_minus_k2)/2};
    }
};