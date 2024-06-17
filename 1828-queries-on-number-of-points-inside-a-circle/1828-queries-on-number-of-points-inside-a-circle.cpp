class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            int cnt = 0;
            int x = queries[i][0], y = queries[i][1], r = queries[i][2];
            for(vector<int> &point: points) {
                if((x-point[0])*(x-point[0]) + (y-point[1])*(y-point[1]) <= r*r) cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
};