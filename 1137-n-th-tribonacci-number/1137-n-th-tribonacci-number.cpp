vector<int> tribo;

class Solution {
public:
    int tribonacci(int n) {
        if(tribo.size() == 0) {
            tribo.resize(38);
            tribo[0] = 0; tribo[1] = tribo[2] = 1;
            for(int i=3; i<38; i++) tribo[i] = tribo[i-1]+tribo[i-2]+tribo[i-3]; 
        }
        return tribo[n];
    }
};