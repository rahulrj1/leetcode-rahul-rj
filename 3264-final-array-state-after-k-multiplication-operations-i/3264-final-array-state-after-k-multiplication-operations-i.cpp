class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<nums.size(); i++) pq.push({-nums[i], -i});
        while(k--) {
            auto curr = pq.top(); pq.pop(); 
            pq.push({curr.first * multiplier, curr.second});
        }
        vector<int> res(nums.size());
        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            res[-curr.second] = -curr.first;
        }
        return res;
    }
};