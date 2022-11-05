class Node {
public:
    Node* child[26];
    bool isEnd;
    Node() {
        for(int i=0; i<26; i++) child[i] = NULL;
        isEnd = false;
    }
};

void InsertWord(Node* root, string w) {
    Node* node = root;
    for(int i=0; i<w.length(); i++) {
        if(node->child[w[i]-'a'] == NULL) node->child[w[i]-'a'] = new Node();
        node = node->child[w[i]-'a'];
    }
    node->isEnd = true;
}

void findAns(vector<string> &ans, Node* node, vector<vector<char>> &board, int x, int y, string &s, vector<vector<bool>> &vis) {
    Node* root = node; 
    if((root->child[(board[x][y] - 'a')]) == NULL) return;
    vis[x][y] = true;
    root = root->child[board[x][y] - 'a'];
    s.push_back(board[x][y]); 
    if(root->isEnd) ans.push_back(s), root->isEnd = false;
    if(x-1 >= 0 && !vis[x-1][y]) findAns(ans, root, board, x-1, y, s, vis);
    if(y-1 >= 0 && !vis[x][y-1]) findAns(ans, root, board, x, y-1, s, vis);
    if(x+1 < board.size() && !vis[x+1][y]) findAns(ans, root, board, x+1, y, s, vis);
    if(y+1 < board[0].size() && !vis[x][y+1]) findAns(ans, root, board, x, y+1, s, vis);
    s.pop_back();
    vis[x][y] = false;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for(auto w: words) InsertWord(root, w);
        vector<string> ans;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                string s = "";
                vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), false));
                findAns(ans, root, board, i, j, s, vis);
            }
        }
        return ans;
    }
};