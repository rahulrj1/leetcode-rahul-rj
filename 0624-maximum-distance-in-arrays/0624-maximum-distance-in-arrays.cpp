class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        multiset<int> m;
        multiset<int, greater<int>> M;
        
        int ans = 0;
        for(vector<int> a: arrays) m.insert(a[0]), M.insert(a.back());
        for(vector<int> a: arrays) {
            int m1 = a[0], M1 = a.back();
            m.erase(m.find(m1)), M.erase(M.find(M1));
            int tempAns = max(abs(m1-*(M.begin())), abs(M1-*(m.begin())));
            ans = max(ans, tempAns);
            m.insert(m1), M.insert(M1);
        }
        return ans;
    }
};