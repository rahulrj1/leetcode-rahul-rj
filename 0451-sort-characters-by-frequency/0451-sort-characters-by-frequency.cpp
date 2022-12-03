class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto c: s) mp[c]++;
        string ans = "";
        map<int, vector<char>> revm;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            revm[it->second].push_back(it->first);
        }
        for(auto it = revm.rbegin(); it != revm.rend(); it++) {
            for(auto c: it->second) {
                for(int i=0; i<it->first; i++) ans.push_back(c);
            }
        }
        return ans;
    }
};