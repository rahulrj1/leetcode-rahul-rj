class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        for(vector<int> &p: matches) {
            if(mp.find(p[0]) == mp.end()) mp[p[0]] = 0;
            mp[p[1]]++;
        }
        vector<vector<int>> ans = {{}, {}};
        for(auto &it: mp) {
            if(it.second == 0) ans[0].push_back(it.first);
            else if(it.second == 1) ans[1].push_back(it.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};