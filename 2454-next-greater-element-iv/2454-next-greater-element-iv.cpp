class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> prev, curr, temp;
        for(int i=0; i<nums.size(); i++) {
            while(!prev.empty() && nums[prev.top()] < nums[i]) ans[prev.top()] = nums[i], prev.pop();
            while(!curr.empty() && nums[curr.top()] < nums[i]) temp.push(curr.top()), curr.pop();
            while(!temp.empty()) prev.push(temp.top()), temp.pop();
            curr.push(i);
        }
        return ans;
    }
};