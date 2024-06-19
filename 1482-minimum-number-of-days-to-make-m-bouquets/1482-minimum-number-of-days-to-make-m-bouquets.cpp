class Solution {
public:
    bool isPossible(int cand, vector<int> &bloomDay, int m, int k) {
        int numB = 0, currFlow = 0;
        for(int b: bloomDay) {
            if(b <= cand) currFlow++;
            else currFlow = 0;
            if(currFlow == k) numB++, currFlow = 0;
        }
        // cout<<numB<<" ";
        return numB >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL*m*k > 1LL*n) return -1;
        int l = 1, h = *max_element(bloomDay.begin(), bloomDay.end());
        int res = h;
        while(l <= h) {
            int mid = l + (h-l)/2;
            // cout<<mid<<" ";
            if(isPossible(mid, bloomDay, m, k)) {
                res = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};