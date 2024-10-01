class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(k == 1) return true;
        vector<int> cnt(k, 0);
        for(int &num: arr) cnt[((num%k)+k)%k]++; // reaminder
        
        for(int i=1; i<(k/2); i++) {
            if(cnt[i] != cnt[k-i]) return false;
        }
        
        if(cnt[0]%2 != 0) return false; // exactly divisible
        if(k&1) { 
            if(cnt[k/2] != cnt[k-(k/2)]) return false;
        } else { 
            if(cnt[k/2]%2 != 0) return false;
        }
        return true;
    }
};