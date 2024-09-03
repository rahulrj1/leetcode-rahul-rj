class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char &c: s) num += to_string(c-'a'+1);
        for(int i=0; i<k; i++) {
            int z = 0;
            for(char &c: num) z += (c-'0');
            num = to_string(z);
        }
        return stoi(num);
    }
};