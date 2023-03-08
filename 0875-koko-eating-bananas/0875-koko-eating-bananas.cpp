class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while(l <= r) {
            int m = l + (r-l)/2;
            long hr = 0;
            for(auto p: piles) {
                hr += (long)(p/m);
                if(p%m) hr++;
            }
            if(hr <= h) ans = min(ans, m), r = m-1;
            else l = m+1;
        }
        return ans;
    }
};