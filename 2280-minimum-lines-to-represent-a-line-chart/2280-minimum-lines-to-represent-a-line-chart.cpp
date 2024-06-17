class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        int res = 1, n = stockPrices.size();
        if(n == 1) return 0;
        for(int i=2; i<n; i++) {
            // slope of (i-2)..(i-1) and (i-1)..i
            long prev_slope = 1LL*(stockPrices[i-2][1] - stockPrices[i-1][1])*(stockPrices[i-1][0] - stockPrices[i][0]);
            long curr_slope = 1LL*(stockPrices[i-1][1] - stockPrices[i][1])*(stockPrices[i-2][0] - stockPrices[i-1][0]);
            if(prev_slope != curr_slope) res++;
        }
        return res;
    }
};