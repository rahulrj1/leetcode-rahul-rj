class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> prefix(n); prefix[0] = grumpy[0] == 1 ? 0 : customers[0];
        vector<int> suffix(n); suffix[n-1] = grumpy[n-1] == 1 ? 0 : customers[n-1];
        
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + (grumpy[i] == 1 ? 0 : customers[i]);
            suffix[n-1-i] = suffix[n-i] + (grumpy[n-1-i] == 1 ? 0 : customers[n-i-1]);
        }
        
        int happyWindow = 0, res = prefix[n-1];
        for(int i=0; i<minutes; i++) happyWindow += customers[i];
        
        for(int start=0; start+minutes<=n; start++) {
            int left = start == 0 ? 0 : prefix[start-1];
            int right = start+minutes == n ? 0 : suffix[start+minutes];
            res = max(res, left + happyWindow + right);
            
            happyWindow -= customers[start];
            if(start+minutes < n) happyWindow += customers[start+minutes];
        }
        
        return res;
    }
};