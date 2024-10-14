class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int> pq;
        
        for(int &num: nums) pq.push(num);
        for(int i=0; i<k; i++) {
            int curr = pq.top(); pq.pop();
            pq.push(ceil(1.0*curr/3));
            
            res += 1LL*curr;
        }
        
        return res;
    }
};