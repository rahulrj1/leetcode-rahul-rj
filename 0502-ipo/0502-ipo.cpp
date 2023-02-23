class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> proj;
        for(int i=0; i<n; i++) proj.push_back({capital[i], profits[i]});
        sort(proj.begin(), proj.end());
        
        priority_queue<int> pq;
        int ptr = 0;
        for(int i=0; i<k; i++) {
            while(ptr < n && proj[ptr].first <= w) pq.push(proj[ptr++].second);
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};