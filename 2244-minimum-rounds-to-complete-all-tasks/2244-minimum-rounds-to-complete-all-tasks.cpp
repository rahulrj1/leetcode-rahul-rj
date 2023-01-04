class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(int t: tasks) mp[t]++;
        for(auto it: mp) {
            int n = it.second;
            // 2x + 3y = n
            // we have to minimize x + y
            if(n == 1) return -1;
            if(n&1) {
                int z = (n/3);
                z *= 3;
                if(~(z&1)) z -= 3;
                ans += (z/3 + (n-z)/2);
            }
            else {
                int z = (n/3);
                z *= 3;
                if(z&1) z -= 3;
                ans += (z/3 + (n-z)/2);
            }
        }
        return ans;
    }
};