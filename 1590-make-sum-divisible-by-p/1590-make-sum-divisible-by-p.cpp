class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem = 0; 
        for(int &num: nums) rem += num, rem %= p;
        if(rem == 0) return 0;
        
        // find shortest subarray whose sum % p = rem
        int n = nums.size();
        int sum = 0, res = n+1;
        unordered_map<int, int> mp; mp[0] = -1;
        for(int i=0; i<n; i++) {
            sum += nums[i], sum %= p;
            
            if(mp.find((sum-rem+p)%p) != mp.end()) res = min(res, i-mp[(sum-rem+p)%p]);
            mp[sum] = i;
        }
        if(res >= n) res = -1;
        return res;
    }
};