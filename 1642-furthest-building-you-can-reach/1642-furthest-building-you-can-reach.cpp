class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> b;
        for(int i=1; i<n; i++) {
            int breq = max(heights[i] - heights[i-1], 0); 
            
            if(breq > bricks && ladders && !b.empty() && b.top() > breq) {
                bricks += b.top();
                b.pop();
                ladders--;
            } 
            
            if(breq > bricks) {
                if(ladders) ladders--;
                else return i-1;
            }
            else {
                b.push(breq);
                bricks -= breq;
            } 
        }
        return n-1;
    }
};