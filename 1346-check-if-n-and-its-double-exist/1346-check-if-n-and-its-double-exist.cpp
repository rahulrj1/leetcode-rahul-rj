class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for(int &a: arr) {
            if(s.find(2*a) != s.end()) return true;
            if(((a%2) == 0) && s.find(a/2) != s.end()) return true;
            s.insert(a);
        }
        return false;
    }
};