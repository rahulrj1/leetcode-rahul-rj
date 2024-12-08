class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int> > sv;
        vector<vector<int> > ev;
        
        for(vector<int> &e: events) {
            sv.push_back({e[0], e[2]});
            ev.push_back({e[1], e[2]});
        }
        
        sort(sv.begin(), sv.end());
        sort(ev.begin(), ev.end());
        
        int res = 0, emax = 0, j = 0; // till j-1 of start array
        for(int i=0; i<sv.size(); i++) {
            while(j<ev.size() && ev[j][0] < sv[i][0]) emax = max(emax, ev[j++][1]);
            res = max(res, sv[i][1] + emax);
        }
        return res;
    }
};