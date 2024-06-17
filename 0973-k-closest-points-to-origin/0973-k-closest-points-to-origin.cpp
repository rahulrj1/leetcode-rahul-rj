class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(vector<int> point: points) {
            pq.push({point[0]*point[0] + point[1]*point[1], point[0], point[1]});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            vector<int> point = pq.top(); pq.pop();
            res.push_back({point[1], point[2]});
        }
        return res;
    }
};