class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        vector<int> v = queries;
        sort(v.begin(), v.end());
        int j = 0, sum = 0;
        for(int i=0; i<v.size(); i++) {
            while(j<nums.size() && sum + nums[j] <= v[i]) sum += nums[j++];
            mp[v[i]] = j;
        }
        for(int i=0; i<v.size(); i++) v[i] = mp[queries[i]];
        return v;
    }
};