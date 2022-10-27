class Solution {
public:
	// Renaming img1 and img2 as v1 and v2 respectively to make code look less verbose.
    int largestOverlap(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        int n = v1.size();
        vector<pair<int,int>> i1, i2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(v1[i][j] == 1) i1.push_back({i,j});
                if(v2[i][j] == 1) i2.push_back({i,j});
            }
        }
        
        int ans = 0;
        map<pair<int,int>,int> mp;
        for(auto &[a,b]:i1){
            for(auto &[c,d]:i2) mp[{c-a,d-b}]++;
        }
        for(auto &[_,count]:mp) ans = max(ans,count);
        
        return ans;
    }
};