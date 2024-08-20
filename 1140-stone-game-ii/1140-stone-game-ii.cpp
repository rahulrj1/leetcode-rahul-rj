class Solution {
public:
    int helper(vector<int> &piles, int id, int m, map<vector<int>, int> &mp) {
        if(mp.find({id, m}) != mp.end()) return mp[{id, m}];
        int ans = 0, score = 0;
        for(int x=1; x<=2*m && id+x-1<piles.size(); x++) {
            score += piles[id+x-1];
            int oppoScore = helper(piles, id+x, max(m, x), mp);
            int remSum = 0;
            for(int i=id+x; i<piles.size(); i++) remSum += piles[i];
            ans = max(ans, score+remSum-oppoScore);
        }
        return mp[{id, m}] = ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        map<vector<int>, int> mp;
        return helper(piles, 0, 1, mp);
    }
};