class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_multiset<int> ms;
        ms.insert(0);
        int remainder = 0, res = 0;
        for(int &n: nums) {
            remainder = (remainder + n) % k;
            if(remainder < 0) remainder += k;
            res += ms.count(remainder);
            ms.insert(remainder);
        }
        return res;
    }
};