class Solution {
public:
    void dfs(unordered_map<string, vector<string> > &parent, string& word, vector<string> &temp, vector<vector<string> > &res) {
        temp.push_back(word);
        if(parent[word].size() == 0) {
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            reverse(temp.begin(), temp.end());
        }
        for(string par: parent[word]) {
            dfs(parent, par, temp, res);
        }
        temp.pop_back();
    }
    
    vector<vector<string>> buildAns(unordered_map<string, vector<string> > &parent, string& word) {
        vector<vector<string> > res;
        
        vector<string> temp;
        dfs(parent, word, temp, res);
        
        return res;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(string &w: wordList) dict.insert(w);
        
        queue<string> q; q.push(beginWord);
        auto it = dict.find(beginWord);
        if(it != dict.end()) dict.erase(it);
        
        unordered_map<string, vector<string> > parent;
        bool ansFound = false;
        while(!q.empty()) {
            int sz = q.size();
            unordered_set<string> currentLevelWords;
            while(sz--) {
                string curr = q.front(); q.pop();
                string next = curr;
                for(int i=0; i<curr.length(); i++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        next[i] = c;
                        it = dict.find(next);
                        if(it != dict.end()) {
                            parent[next].push_back(curr);
                            if(next == endWord) ansFound = true;
                            currentLevelWords.insert(next);
                        }
                    }
                    next[i] = curr[i];
                }
            }
            for(string w: currentLevelWords) dict.erase(w), q.push(w);
            if(ansFound) return buildAns(parent, endWord);
        }
        for(auto it: parent) {
            cout<<endl;
            cout<<it.first<<" ";
            for(auto s: it.second) cout<<s<<" "; cout<<endl;
        }
        return {};
    }
};