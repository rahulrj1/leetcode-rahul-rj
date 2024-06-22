class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp; mp[0]++;
        int odd = 0, res = 0;
        for(int num: nums) {
            if(num&1) odd++;
            res += mp[odd-k];
            mp[odd]++;
        }
        return res;
    }
};