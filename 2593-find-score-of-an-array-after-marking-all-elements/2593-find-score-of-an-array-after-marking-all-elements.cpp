class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> mpq;
        vector<bool> marked(nums.size(), false);
        for(int i=0; i<nums.size(); i++) {
            mpq.push({nums[i], i});
        }
        while(!mpq.empty()) {
            auto curr = mpq.top(); mpq.pop();
            int idx = curr.second;
            if(marked[idx]) continue;
            res += 1LL * curr.first; 
            if(idx-1>=0) marked[idx-1] = true;
            if(idx+1<nums.size()) marked[idx+1] = true;
        }
        return res;
    }
};