class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1); left[0] = nums[0];
        vector<int> right(n, 1); right[n-1] = nums[n-1];
        for(int i=1; i<n; i++) {
            left[i] = left[i-1]*nums[i];
            right[n-i-1] = right[n-i]*nums[n-i-1];
        } 
        vector<int> res(n, 1);
        for(int i=0; i<n; i++) {
            if(i-1 >= 0) res[i] *= left[i-1];
            if(i+1 < n) res[i] *= right[i+1];
        }
        return res;
    }
};