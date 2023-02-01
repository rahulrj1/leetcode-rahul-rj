class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a = str1.length(), b = str2.length();
        int g = __gcd(a, b);
        string rep = str1.substr(0, g);
        string s1 = "", s2 = "";
        for(int i=0; i<a/g; i++) s1 += rep;
        for(int i=0; i<b/g; i++) s2 += rep;
        if(s1 == str1 && s2 == str2) return rep;
        return "";
    }
};