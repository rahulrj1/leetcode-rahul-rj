class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> cnt(102, 0);
        
        for(int &num: nums) cnt[(num<100) ? num : 100]++;
        for(int k=100; k>0; k--) {
            cnt[k] += cnt[k+1];
            if(k == cnt[k]) return k;
        }
        return -1;
    }
};