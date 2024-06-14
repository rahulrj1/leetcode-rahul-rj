class Solution {
public:
    int mirrorReflection(int p, int q) {
        int z = lcm(p, q);

        if((z/p)&1) { 
            if((z/q)&1) return 1;
            return 2;
        }
        else {
            return 0;
        }
    }
};