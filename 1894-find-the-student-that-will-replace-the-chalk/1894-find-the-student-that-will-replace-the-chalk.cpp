class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = 0;
        for(int &c: chalk) s += (long long) c;
        
        int z = k % s;
        for(int i=0; i<chalk.size(); i++) {
            if(z < chalk[i]) return i;
            z -= chalk[i];
        }
        
        return 0;
    }
};