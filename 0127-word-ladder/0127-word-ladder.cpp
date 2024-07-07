class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st; for(string &w: wordList) st.insert(w);
        
        int level = 1;
        queue<string> q; q.push(beginWord); 
        auto it = st.find(beginWord);
        if(it != st.end()) st.erase(beginWord);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                string curr = q.front(); q.pop();
                string next = curr;
                for(int i=0; i<curr.length(); i++) {
                    for(char j='a'; j<='z'; j++) {
                        next[i] = j;
                        it = st.find(next);
                        if(it != st.end()) {
                            if(next == endWord) return level+1;
                            st.erase(it);
                            q.push(next);
                        }
                    }
                    next[i] = curr[i];
                }
            }
            level++;
        }
        return 0;
    }
};