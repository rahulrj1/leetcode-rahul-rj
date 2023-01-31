class Solution {
public:
    int findAns(vector<vector<int>> &dp, vector<vector<int>> &v, int prev, int index) {
        if(index == v.size()) return 0;
        if(dp[prev+1][index] != -1) return dp[prev+1][index];
        
        if(prev == -1 || v[index][1] >= v[prev][1]) {
            return dp[prev+1][index] = max(findAns(dp, v, prev, index+1), v[index][1] + findAns(dp, v, index, index+1));
        }
        return dp[prev+1][index] = findAns(dp, v, prev, index+1);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> v;
        for(int i=0; i<scores.size(); i++) v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());
        vector<vector<int>> dp(scores.size(), vector<int> (scores.size(), -1));
        return findAns(dp, v, -1, 0);
    }
};