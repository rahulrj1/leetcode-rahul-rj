class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        for(int i=num.size()-1; i>=0; i--) {
            num[i] = num[i] + (k%10) + carry;
            k /= 10;
            carry = num[i] > 9 ? 1 : 0;
            num[i] %= 10;
        }
        while(k != 0) {
            num.insert(num.begin(), 0);
            num[0] = num[0] + (k%10) + carry;
            k /= 10;
            carry = num[0] > 9 ? 1 : 0;
            num[0] %= 10;
        }
        if(carry) num.insert(num.begin(), 1);
        return num;
    }
};