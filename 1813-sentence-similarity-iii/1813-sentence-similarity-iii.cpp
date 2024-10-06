class Solution {
public:
    vector<string> helper(string &s) {
        vector<string> res;
        string t = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] != ' ') t += s[i];
            else {
                res.push_back(t); 
                t = "";
            }
        }
        res.push_back(t);
        return res;
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> w1 = helper(sentence1);
        vector<string> w2 = helper(sentence2);
        
        int l1 = 0, l2 = 0;
        int r1 = w1.size()-1 , r2 = w2.size()-1;
        
        // remove same words from beginning 
        while(l1<=r1 && l2<=r2 && w1[l1] == w2[l2]) l1++, l2++;
        
        // remove same words from end
        while(l1<=r1 && l2<=r2 && w1[r1] == w2[r2]) r1--, r2--;
        
        // check if any one of w1/w2 is empty
        return (l1 == r1+1 || l2 == r2+1);
    }
};