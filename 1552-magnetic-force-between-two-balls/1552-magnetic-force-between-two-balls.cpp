class Solution {
public:
    bool isPossibleCorGreaterThanC(vector<int> &position, int &m, int &c) {
        int numBalls = 1, prev = position[0];
        for(int i=1; i<position.size(); i++) {
            if(position[i] - prev >= c) {
                numBalls++;
                prev = position[i];
            }
        }
        return numBalls >= m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size(), res;
        int l = 1, h = (position[n-1]-position[0]);
        while(l <= h) {
            int c = l + (h-l)/2;
            if(isPossibleCorGreaterThanC(position, m, c)) {
                res = c;
                l = c + 1;
            }
            else {
                h = c - 1;
            }
        }
        return res;
    }
};