class Solution {
public:
    static bool cmp(int &a, int &b) {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        
        return (s1 > s2);
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0) return "0";
        
        string res = "";
        for(int &n: nums) res += to_string(n);
        return res;
    }
};