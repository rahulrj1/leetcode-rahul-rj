class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 1, left = 0;
        deque<int> incq; incq.push_back(0);
        deque<int> decq; decq.push_back(0);
        for(int i=1; i<nums.size(); i++) {
            while(!incq.empty() && nums[incq.back()] > nums[i]) incq.pop_back();
            while(!decq.empty() && nums[decq.back()] < nums[i]) decq.pop_back();
            
            incq.push_back(i);
            decq.push_back(i);
            
            int maxEle = nums[decq.front()];
            int minEle = nums[incq.front()];
            
            while(maxEle - minEle > limit) {
                if(incq.front() > decq.front()) left = decq.front() + 1, decq.pop_front();
                else left = incq.front() + 1, incq.pop_front();
                
                maxEle = nums[decq.front()], minEle = nums[incq.front()];
            }
            res = max(res, i + 1 - left);
        }
        return res;
    }
};