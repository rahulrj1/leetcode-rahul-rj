class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans; int i=0, n = intervals.size();
        for(; i<n && intervals[i][0] <= newInterval[0]; i++) ans.push_back(intervals[i]);
        if(ans.size() != 0 && newInterval[0] <= ans.back()[1]) ans.back()[1] = max(newInterval[1], ans.back()[1]);
        else ans.push_back(newInterval);
        for(; i<n; i++) {
            if(intervals[i][0] <= ans.back()[1]) ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};