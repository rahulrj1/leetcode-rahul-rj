class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp; 
        int i=0, j=0, ans = 1;
        while(j<fruits.size()) {
            if(mp.size() < 3) mp[fruits[j++]]++;
            else {
                mp[fruits[i++]]--;
                if(mp[fruits[i-1]] == 0) mp.erase(fruits[i-1]);
            }
            
            if(mp.size() < 3) ans = max(ans, j-i);
        }
        return ans;
    }
};