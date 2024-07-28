class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int> > adjlist(n+1);
        for(vector<int> &e: edges) adjlist[e[0]].push_back(e[1]), adjlist[e[1]].push_back(e[0]);
        
        bool flag = false;
        vector<int> dis(n+1, -1); dis[n] = 0;
        queue<int> q; q.push(n);
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(int nbr: adjlist[curr]) {
                if(dis[nbr] == -1) {
                    q.push(nbr);
                    dis[nbr] = dis[curr] + 1;
                }
            }
        }
        
        q.push(1);
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(int nbr: adjlist[curr]) {
                if(dis[nbr] == dis[curr]) {flag = true; cout<<"Rahul";}
                else if(dis[nbr] == dis[curr]-1) q.push(nbr);
            }
        }
        
        int distance = flag == false ? dis[1] + 2 : dis[1] + 1;
        cout<<flag;
        int t = 0;
        for(int i=1; i<=distance; i++) {
            t += time; 
            if((t / change)&1) {
                if(distance != i)
                    t += change - (t % change);
            }
        }
        return t;
    }
};