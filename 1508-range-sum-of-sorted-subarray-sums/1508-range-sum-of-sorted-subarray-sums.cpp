class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> cnt(1e5 + 1, 0);
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                cnt[sum]++;
            }
        }
        int M = 1e9 + 7;
        
        long idx=0, tillLeftMinusOne = 0, tillRight = 0;
        for(long i=1; i<=1e5; i++) {
            if(cnt[i] == 0) continue;
            
            if(idx + cnt[i] <= left-1) tillLeftMinusOne += (cnt[i]*i)%M;
            else if(idx <= left-1) tillLeftMinusOne += ((left-1-idx)*i)%M;
            
            if(idx + cnt[i] <= right) tillRight += (cnt[i]*i)%M;
            else if(idx <= right) tillRight += ((right-idx)*i)%M;
            idx += cnt[i];
            
            tillRight %= M;
            tillLeftMinusOne %= M;
            if(idx >= right) break;
        }
        tillRight %= M;
        return tillRight - tillLeftMinusOne;
    }
};