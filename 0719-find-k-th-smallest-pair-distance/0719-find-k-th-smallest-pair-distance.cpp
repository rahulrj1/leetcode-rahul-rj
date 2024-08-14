class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size(), M = *max_element(nums.begin(), nums.end());
        vector<int> buckets(M+1, 0);
        
        for(int i=0; i<n; i++) 
            for(int j=i+1; j<n; j++) {
                int dis = abs(nums[i] - nums[j]);
                buckets[dis]++;
            }
        
        int idx = 0;
        for(int dis=0; dis<=M; dis++) {
            idx += buckets[dis];
            if(idx >= k) return dis;
        }
        return -1;
    }
};