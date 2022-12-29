class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0; i<n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        
        vector<int> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        long long curr_time = 0;
        int i = 0;
        
        while(i<n || !pq.empty()) {
            if(pq.empty() && curr_time < tasks[i][0]) curr_time = tasks[i][0];
            
            while(i<n && tasks[i][0] <= curr_time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            curr_time += (long long)pq.top()[0];
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
};