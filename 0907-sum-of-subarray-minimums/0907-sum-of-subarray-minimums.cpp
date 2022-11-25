class Solution {
public:
    void nextLess(vector<int> &arr, vector<int> &ans) {
        int n = arr.size();
        stack<int> s;
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> z(n);
        nextLess(arr, z);
        long long ans = 0;
        for(int i=0; i<n; i++) {
            while(!s.empty() && arr[s.top()] > arr[i]) s.pop();
            int pl = s.empty() ? -1 : s.top();
            s.push(i);
            ans += 1LL*(arr[i])*(i-pl)*(z[i]-i);
            ans %= 1000000007;
        }
        return ans;
    }
};