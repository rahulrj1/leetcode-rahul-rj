class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int &p: piles) pq.push(p);
        for(int i=0; i<k; i++) {
            int z = pq.top(); pq.pop();
            pq.push(z - (z/2));
        }
        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};