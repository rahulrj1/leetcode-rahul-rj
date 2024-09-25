class Node {
public:
    int cnt;
    unordered_map<char, Node*> child;
    Node() {
        cnt = 0;
    }
};

class Solution {
    void insert(string &s, Node* root) {
        Node* curr = root;
        for(char &c: s) {
            if(curr->child.find(c) == curr->child.end()) curr->child[c] = new Node();
            curr = curr->child[c];
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
                curr = curr->child[c];
                res[i] += curr->cnt;
            }
        }
        return res;
    }
};