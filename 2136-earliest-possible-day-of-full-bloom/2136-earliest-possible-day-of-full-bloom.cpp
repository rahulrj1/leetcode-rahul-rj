class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> v;
        for(int i=0; i<plantTime.size(); i++) v.push_back({growTime[i], plantTime[i]});
        sort(v.rbegin(), v.rend());
        
        int ans = 0;
        int start = 0;
        for(int i=0; i<plantTime.size(); i++) {
            ans = max(ans, start+v[i][0]+v[i][1]+1);
            start += v[i][1]; 
        }
        return ans-1;
    }
};