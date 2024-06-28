class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(vector<int> &road: roads) degree[road[0]]++, degree[road[1]]++;
        
        long long res = 0;
        sort(degree.begin(), degree.end());
        for(int i=0; i<n; i++) res += 1LL*(i+1)*degree[i];
        
        return res;
    }
};