class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        
        vector<vector<int>> dp;
        for(int i=0; i<difficulty.size(); i++) dp.push_back({difficulty[i], profit[i]});
        sort(dp.begin(), dp.end());
        
        int maxProfit = 0, idx=0, res=0;
        for(int i=0; i<worker.size(); i++) {
            while(idx<dp.size() && dp[idx][0] <= worker[i]) maxProfit = max(maxProfit, dp[idx++][1]);
            res += maxProfit;
        }
        return res;
    }
};