class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> indegree(k+1, 0);
        unordered_map<int, vector<int> > mp;
        for(vector<int> &r: rowConditions) indegree[r[1]]++, mp[r[0]].push_back(r[1]);
        queue<int> q; 
        for(int i=1; i<=k; i++) if(indegree[i] == 0) q.push(i); 
        vector<int> row(k+1, -1); int z = 0;
        while(!q.empty()) {
            // z denotes the row number
            int curr = q.front(); q.pop();
            row[curr] = z++;
            for(int nbr: mp[curr]) {
                if(indegree[nbr]-- == 1) q.push(nbr);
            }
        }
        if(z != k) return {};
        
        indegree = vector<int> (k+1, 0);
        mp.clear();
        for(vector<int> &c: colConditions) indegree[c[1]]++, mp[c[0]].push_back(c[1]);
        for(int i=1; i<=k; i++) if(indegree[i] == 0) q.push(i);
        vector<int> col(k+1, -1); z = 0;
        while(!q.empty()) {
            // z denotes the col number
            int curr = q.front(); q.pop();
            col[curr] = z++;
            for(int nbr: mp[curr]) {
                if(indegree[nbr]-- == 1) q.push(nbr);
            }
        }
        if(z != k) return {};
        
        vector<vector<int> > res(k, vector<int> (k, 0));
        for(int i=1; i<=k; i++) res[row[i]][col[i]] = i;
        return res;
        
        // 312 and 321
        
    }
};