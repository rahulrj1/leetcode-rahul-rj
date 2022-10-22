class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, cost = INT_MAX;
        for(int i=0; i<prices.size(); i++) {
            cost = min(cost, prices[i]);
            ans = max(ans, prices[i]-cost);
        }
        return ans;
    }
};