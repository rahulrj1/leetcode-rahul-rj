class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0, j = 0;
        for(int i=0; i<k; i++) {
            ans++;
            while(j<arr.size() && ans == arr[j]) ans++, j++;
        }
        return ans;
    }
};