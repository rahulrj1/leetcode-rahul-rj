class Solution {
public:
    unordered_map<string, vector<int>> dp;
    
    int findVal(int l, int r, char c) {
        if(c == '+') return l+r;
        if(c == '-') return l-r;
        return l*r;
    }
    
    vector<int> helper(string exp) {
        vector<int> res;
        if(dp.find(exp) != dp.end()) return dp[exp];
        for(int i=0; i<exp.length(); i++) {
            if(!isdigit(exp[i])) {
                vector<int> left = helper(exp.substr(0, i));
                vector<int> right = helper(exp.substr(i+1));
                
                for(int l: left)
                    for(int r: right)
                        res.push_back(findVal(l, r, exp[i]));
            }
        }
        if(res.empty()) res.push_back(stoi(exp));
        return res;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        dp.clear();
        return helper(expression);
    }
};