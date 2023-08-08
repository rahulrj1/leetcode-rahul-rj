class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> v(n, 0); int sell = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            sell = max(sell, prices[i]);
            v[i] = max(v[i+1], sell-prices[i]);
        }
        
        int cost = prices[0], res = v[0], profit = 0;
        for(int i=1; i<n-1; i++) {
            cost = min(cost, prices[i]);
            profit = max(profit, prices[i] - cost);
            res = max(res, profit + v[i+1]);
        }
        
        return res;
    }
};