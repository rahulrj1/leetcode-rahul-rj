class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int num: nums) temp ^= num;
        
        int z = -1;
        for(int i=0; i<32; i++) if(temp&(1<<i)) { z = i; break; }
        
        int temp2 = 0;
        for(int num: nums) if(num&(1<<z)) temp2 ^= num;
        
        return {temp2, temp^temp2};
    }
};