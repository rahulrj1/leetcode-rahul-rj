class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> z, res(arr1.size());
        for(int num: arr2) mp[num]++;
        for(int num: arr1) {if(mp[num] > 0) mp[num]++; else z.push_back(num);}
        sort(z.begin(), z.end());
        int idx = 0;
        for(int num: arr2) {
            for(int i=1; i<mp[num]; i++) {
                res[idx++] = num;
            }
        }
        for(int i=0; i<z.size(); i++) res[idx++] = z[i];
        return res;
    }
};