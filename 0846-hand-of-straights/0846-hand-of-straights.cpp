class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        
        map<int, int> freq;
        for(int &num: hand) freq[num]++;
        while(!freq.empty()) {
            auto it = freq.begin(); 
            int num = it->first;
            for(int i=0; i<groupSize; i++) {
                if(freq[num] == 0) return false;
                freq[num]--;
                if(freq[num] == 0) freq.erase(num);
                num++;
            }
        }
        return true;
    }
};