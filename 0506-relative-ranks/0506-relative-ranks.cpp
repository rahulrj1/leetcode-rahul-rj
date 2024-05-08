class Solution {
public:
    static bool splSort(pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
    }
    
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int> > sp;
        
        for(int i=0; i<n; i++) sp.push_back({score[i], i});
        sort(sp.rbegin(), sp.rend(), splSort);
        vector<string> res(n);
        for(int i=0; i<n; i++) {
            if(i==0) res[sp[i].second] = "Gold Medal";
            else if(i==1) res[sp[i].second] = "Silver Medal";
            else if(i==2) res[sp[i].second] = "Bronze Medal";
            else res[sp[i].second] = to_string(i+1);
        }
        return res;
    }
};