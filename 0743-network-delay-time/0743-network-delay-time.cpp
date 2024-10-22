class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int> > > adjlist;
        for(vector<int> &t: times) {
            int x = t[0], y = t[1], wt = t[2];
            adjlist[x].push_back(make_pair(y, wt));
        }
        
        vector<int> t(n+1, 1e5); t[k] = 0;
        set<pair<int, int> > s;
        s.insert({0, k}); // time, node
        int vis = 0, latestTime = 0;
        while(!s.empty()) {
            auto curr = s.begin();
            int currNode = curr->second;
            int currTime = curr->first;
            s.erase(curr);
            vis++;
            latestTime = currTime;
            
            for(auto nbr: adjlist[currNode]) {
                int nbrNode = nbr.first;
                int nbrTime = nbr.second;
                
                if(t[nbrNode] > currTime + nbrTime) {
                    auto it = s.find(make_pair(t[nbrNode], nbrNode));
                    if(it != s.end()) s.erase(it);
                    
                    t[nbrNode] = currTime + nbrTime;
                    s.insert(make_pair(t[nbrNode], nbrNode));
                }
            }
        }
        if(vis == n) return latestTime;
        return -1;
    }
};