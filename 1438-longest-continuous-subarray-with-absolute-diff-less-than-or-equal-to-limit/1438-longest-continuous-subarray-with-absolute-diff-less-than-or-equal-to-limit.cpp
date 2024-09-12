class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l=0, r=0, res=1;
        deque<int> inc; inc.push_back(0);
        deque<int> dec; dec.push_back(0);
        
        for(int i=1; i<nums.size(); i++) {
            
            // dec queue
            while(!dec.empty() && nums[dec.back()] <= nums[i]) dec.pop_back();
            dec.push_back(i);
            
            // inc queue
            while(!inc.empty() && nums[inc.back()] >= nums[i]) inc.pop_back();
            inc.push_back(i);
            
            r = i;
            while(true) {
                int Max = nums[dec.front()];
                int min = nums[inc.front()];
                
                if(Max-min <= limit) {res = max(res, r - l + 1); break;}
                if(inc.front() == l) inc.pop_front();
                if(dec.front() == l) dec.pop_front();
                l++;
            }
            
        }
        return res;
    }
};