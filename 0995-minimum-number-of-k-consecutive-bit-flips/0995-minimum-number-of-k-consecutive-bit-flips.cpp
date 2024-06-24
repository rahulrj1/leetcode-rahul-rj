class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flips(n+1, 0);
        int sum = 0, res = 0;
        for(int i=0; i<n; i++) {
            sum = (sum + flips[i]) % 2; 
            if(sum < 0) sum += 2;
            
            if(((nums[i]+sum) % 2) == 0) {
                flips[i]++;
                if(i+k > n) return -1;
                flips[i+k]--;
                sum++;
                res++;
            } 
        }
        return res;
    }
};