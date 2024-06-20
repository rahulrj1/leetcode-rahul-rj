class Solution {
public:
    int findParent(int child, vector<int> &parent) {
        if(child == parent[child]) return child;
        return parent[child] = findParent(parent[child], parent);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n); for(int i=0; i<n; i++) parent[i] = i;
        
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(mp.find(email) == mp.end()) {    // email not found
                    mp[email] = i;
                }
                else { // email found
                    int par1 = findParent(mp[email], parent);
                    int par2 = findParent(i, parent);
                    
                    if(par1 != par2) {
                        parent[par1] = par2;
                    }
                }
            }
        }
        
        unordered_map<int, unordered_set<string>> finalmap;
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                int par = findParent(i, parent);
                finalmap[par].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for(auto it: finalmap) {
            vector<string> temp(it.second.begin(), it.second.end());
            sort(temp.rbegin(), temp.rend()); 
            temp.push_back(accounts[it.first][0]);
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};