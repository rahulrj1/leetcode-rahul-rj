class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long sum = 0; 
        unordered_map<int, int> mp; mp[0] = -1;
        for(int i=0; i<nums.size(); i++) {
            sum += (long long)nums[i]; sum %= k;
            if(mp.find(sum) == mp.end()) mp[sum] = i;
            else if(mp[sum] < i-1) return true;
        }
        return false;
    }
};