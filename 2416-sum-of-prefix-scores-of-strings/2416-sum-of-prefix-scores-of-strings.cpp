class Node {
public:
    int cnt;
    Node* child[26];
    Node() {
        cnt = 0;
        for(int i=0; i<26; i++) {
            child[i] = nullptr;
        }
    }
};

class Solution {
    void insert(string &s, Node* root) {
        Node* curr = root;
        for(char &c: s) {
            if(curr->child[c-'a'] == nullptr) curr->child[c-'a'] = new Node();
            curr = curr->child[c-'a'];
            (curr->cnt)++;
        }
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();
        for(string &word: words) {
            insert(word, root);
        }
        int n = words.size();
        vector<int> res(n, 0);
        for(int i=0; i<n; i++) {
            string word = words[i];
            Node* curr = root;
            for(char &c: word) {
                curr = curr->child[c-'a'];
                res[i] += curr->cnt;
            }
        }
        return res;
    }
};