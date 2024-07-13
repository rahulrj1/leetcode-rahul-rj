class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> v;
        for(int i=0; i<positions.size(); i++) {
            v.push_back({positions[i], healths[i], (directions[i]=='R' ? 1 : -1)});
        }
        sort(v.begin(), v.end());
        stack<pair<int, int>> s;
        unordered_map<int, int> mp;
        for(int i=0; i<v.size(); i++) {
            if(v[i][2] == 1) s.push({v[i][0], v[i][1]}); // push the robot's {position, health} in stack
            else {
                int curr = i;
                while(!s.empty()) {
                    pair<int, int> temp = s.top(); s.pop();
                    if(v[i][1] > temp.second) v[i][1]--; // left moving robot has greater health 
                    else if(v[i][1] < temp.second) {s.push({temp.first, temp.second-1}); curr=-1; break;}
                    else {curr=-1; break;}
                }
                if(curr != -1) mp[v[i][0]] = v[i][1]; 
            }
        }
        while(!s.empty()) {
            pair<int, int> temp = s.top(); s.pop();
            mp[temp.first] = temp.second;
        }
        vector<int> res;
        for(int p: positions) {
            if(mp.find(p) != mp.end()) res.push_back(mp[p]);
        }
        return res;
    }
};