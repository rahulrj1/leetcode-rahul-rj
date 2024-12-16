class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, sum = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<k-1; i++) {sum += nums[i]; mp[nums[i]]++;}
        for(int i=k-1; i<nums.size(); i++) {
            sum += 1LL*nums[i];
            mp[nums[i]]++;
            if(mp.size() == k) res = max(res, sum);
            
            sum -= 1LL*nums[i-k+1];
            mp[nums[i-k+1]]--;
            if(mp[nums[i-k+1]] == 0) mp.erase(nums[i-k+1]);
        }
        return res;
    }
};