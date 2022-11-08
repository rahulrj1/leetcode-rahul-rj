class Solution {
public:
    vector<int> sessions;
    unordered_map<string, int> dp;
    
    string encodeState(int pos) {
        string key = to_string(pos);
        vector<int> c = sessions;
        sort(c.begin(), c.end());
        for(int s: c) {
            key += '$' + to_string(s);
        }
        return key;
    }
    
    int helper(vector<int> &tasks, int n, int st, int pos) {
        if(pos >= n) return 0;
        
        string key = encodeState(pos);
        if(dp.find(key) != dp.end()) return dp[key];
        
        sessions.push_back(tasks[pos]);
        int ans = 1 + helper(tasks, n, st, pos+1);
        sessions.pop_back();
        
        for(int i=0; i<sessions.size(); i++) {
            if(sessions[i] + tasks[pos] <= st) {
                sessions[i] += tasks[pos];
                ans = min(ans, helper(tasks, n, st, pos+1));
                sessions[i] -= tasks[pos];
            }
        }
        return dp[key] = ans;
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        return helper(tasks, n, sessionTime, 0);
    }
};