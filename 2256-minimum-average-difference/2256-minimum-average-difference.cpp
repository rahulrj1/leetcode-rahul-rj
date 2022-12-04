class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long left = 0, right = 0;
        int n = nums.size(); 
        for(int num: nums) right += num;
        int min_diff = right/n, ans = n-1;
        
        for(int i=0; i<n-1; i++) {
            left += (long long)nums[i];
            right -= (long long)nums[i];
            int diff = abs((int)(left/(i+1)) - (int)(right/(n-i-1)));
            if(min_diff == diff) ans = min(ans, i);
            else if(min_diff > diff) min_diff = diff, ans = i;
        }
        return ans;
    }
};