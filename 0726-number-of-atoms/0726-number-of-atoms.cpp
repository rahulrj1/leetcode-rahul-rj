int i, n;
class Solution {
public:
    map<string, int> parse(string &formula) {
        map<string, int> ans;
        while(i<n && formula[i] != ')') {
            if(formula[i] == '(') {
                i++;
                map<string, int> temp = parse(formula);
                for(auto it = temp.begin(); it != temp.end(); it++) ans[it->first] += it->second;
            }
            else {
                int istart = i++;
                while(i<n && formula[i]<='z' && formula[i]>='a') i++;
                string ele = formula.substr(istart, i-istart);
                istart = i;
                while(i<n && formula[i]<='9' && formula[i]>='0') i++;
                int num = istart < i ? stoi(formula.substr(istart, i-istart)) : 1;
                ans[ele] += num;
            }
        }
        int istart = ++i;
        while(i<n && formula[i]<='9' && formula[i]>='0') i++;
        if(istart < i) {
            int num = stoi(formula.substr(istart, i-istart));
            for(auto it = ans.begin(); it != ans.end(); it++) it->second *= num;
        }
        return ans;
    }
    
    string countOfAtoms(string formula) {
        i = 0, n = formula.length();
        map<string, int> mp = parse(formula);
        string ans = "";
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans += it->first;
            if(it->second != 1) ans += to_string(it->second);
        }
        return ans;
    }
};