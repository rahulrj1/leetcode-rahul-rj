class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int> > mp; // cnt, left, right
        int mc = 1;
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if(mp.find(num) == mp.end()) mp[num] = {1, i, i};
            else {
                mp[num][0]++;
                mp[num][2] = i;
            }
            
            mc = max(mc, mp[num][0]);
        }
        int res = nums.size();
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if(mp.find(num) == mp.end()) continue;
            if(mp[num][0] == mc) {
                int dis = (mp[num][2] - mp[num][1] + 1);
                res = min(dis, res);
            }
            mp.erase(num);
        }
        return res;
    }
};