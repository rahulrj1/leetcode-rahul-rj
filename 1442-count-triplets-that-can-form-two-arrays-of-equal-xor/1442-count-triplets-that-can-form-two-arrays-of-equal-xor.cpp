class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int> > mp; 
        mp[0].push_back(-1);
        int z = 0, res = 0;
        for(int i=0; i<arr.size(); i++) {
            z ^= arr[i];
            for(int left: mp[z]) res += i - left - 1;
            mp[z].push_back(i);
        }
        return res;
    }
};