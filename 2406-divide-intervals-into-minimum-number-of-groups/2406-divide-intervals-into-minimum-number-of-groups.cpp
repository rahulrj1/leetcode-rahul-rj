class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int group = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(vector<int> &inter: intervals) {
            while(!pq.empty() && pq.top() < inter[0]) pq.pop();
            pq.push(inter[1]);
            
            int currSize = pq.size();
            group = max(group, currSize);
        }
        return group;
    }
};