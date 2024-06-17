class Solution {
public:
    int findAns(vector<vector<int>> &bombs, int start, unordered_map<int, vector<int>> &adjlist) {
        vector<bool> vis(bombs.size(), false);
        
        queue<int> q; q.push(start); vis[start] = true;
        int cnt = 1;
        while(!q.empty()) {
            int temp = q.front(); q.pop();
            for(int child: adjlist[temp]) {
                if(!vis[child]) {
                    vis[child] = true;
                    q.push(child);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> adjlist;
        for(int i=0; i<bombs.size(); i++) {
            for(int j=i+1; j<bombs.size(); j++) {
                long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                
                long dis_sq = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
                if(dis_sq <= r1*r1) adjlist[i].push_back(j);
                if(dis_sq <= r2*r2) adjlist[j].push_back(i);
            }
        }
        
        int res = 1;
        for(int start=0; start<bombs.size(); start++) {
            res = max(res, findAns(bombs, start, adjlist));
        }
        return res;
    }
};