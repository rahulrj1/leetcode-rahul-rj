class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, st = 0;
        for(int i=0; i<gas.size(); i++) {
            tank += gas[i] - cost[i];
            if(tank < 0) st = i+1, tank = 0;
        }
        if(st == gas.size()) return -1;
        for(int i=0; i<st; i++) {
            tank += gas[i] - cost[i];
            if(tank < 0) return -1;
        }
        return st;
    }
};