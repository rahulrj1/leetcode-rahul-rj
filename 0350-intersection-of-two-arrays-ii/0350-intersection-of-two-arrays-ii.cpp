class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> cnt(1001, 0);
        for(int& num: nums1) cnt[num]++;
        for(int& num: nums2) {
            if(cnt[num] > 0) {
                res.push_back(num);
                cnt[num]--;
            }
        }
        return res;
    }
};