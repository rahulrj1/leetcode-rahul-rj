class Solution {
public:
    int findNext(vector<int> &nums, int idx) {
        for(int i=idx; i<nums.size(); i++) {
            if(nums[i] == 1) return i;
        }
        return nums.size();
    }
    
    int findAnsWithGoalZero(vector<int> &nums) {
        int res = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) cnt++;
            else {
                res += (cnt+1)*(cnt)/2;
                cnt = 0;
            }
        }
        res += (cnt+1)*(cnt)/2;
        return res;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(); if(goal == 0) return findAnsWithGoalZero(nums);
        
        int prevZeros = 0, nextZeros = 0, i = 0, j = 0, sum = goal;
        while(i<n && nums[i] == 0) i++, prevZeros++;
        j = i;
        while(sum > 0 && j < n) {
            if(nums[j] == 1) sum--;
            j++;
        } 
        
        if(sum > 0) return 0;
        int z = findNext(nums, j), res = 0;
        while(1) {
            // (z - j) zeroes
            nextZeros = (z-j);
            res += (prevZeros + 1)*(nextZeros + 1);
            cout<< (prevZeros + 1)*(nextZeros + 1) << " ";
            
            
            if(j >= n) break; 
            j = z+1;
            int nextI = findNext(nums, i+1);
            prevZeros = (nextI - i - 1);
            i = nextI;
            z = findNext(nums, j);
        }
        return res;
    }
};