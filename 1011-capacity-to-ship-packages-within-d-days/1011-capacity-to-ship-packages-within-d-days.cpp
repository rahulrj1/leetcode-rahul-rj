class Solution {
public:
    bool isPoss(vector<int> &w, int cap, int d) {
        int temp = 0, days = 1;
        for(int i=0; i<w.size(); i++) {
            if(temp + w[i] > cap) temp = w[i], days++;
            else temp += w[i];
        }
        return days <= d;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int hi = 0, lo = weights[0];
        for(int i=0; i<weights.size(); i++) {
            hi += weights[i];
            lo = max(lo, weights[i]);
        }
        int ans = hi;
        while(lo <= hi) {
            int m = (hi + lo)/2;
            if(isPoss(weights, m, days)) ans = min(ans, m), hi = m - 1;
            else lo = m + 1;
        }
        return ans;
    }
};