class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans = 0;
        set<int> fr, bk;
        for(int r: rating) bk.insert(r);
        bk.erase(rating[0]); fr.insert(rating[0]);
        for(int i=1; i<n-1; i++) {
            bk.erase(rating[i]); 
            auto it = fr.lower_bound(rating[i]);
            int less_than = distance(fr.begin(), it);
            it = bk.lower_bound(rating[i]);
            int greater_than = distance(bk.begin(), it);
            int f = fr.size(), b = bk.size();
            ans += less_than*(b-greater_than);
            ans += (f-less_than)*greater_than;
            fr.insert(rating[i]);
        }
        return ans;
    }
};