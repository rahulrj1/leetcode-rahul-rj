unordered_map<int, int> mp;
unordered_map<int, int> val;

class Solution {
public:
    static void change(int n) {
        string s = to_string(n);
        for(int i=0; i<s.length(); i++) {
            s[i] = ('0'+mp[(s[i]-'0')]);
        }
        val[n] = stoi(s);
    }
    
    static bool cmp(int a, int b) {
        if(val[a] < val[b]) return true;
        return false;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        mp.clear();
        val.clear();
        for(int i=0; i<10; i++) mp[i] = mapping[i];
        for(int i=0; i<nums.size(); i++) change(nums[i]);
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};