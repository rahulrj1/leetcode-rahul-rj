class Solution {
public:
    bool isPresent(vector<vector<char>>& board, int x, int y, string &word, int index, vector<vector<bool>> &vis) {
        if(word[index] != board[x][y]) return false;
        vis[x][y] = true;
        if(index == word.length()-1) return true;
        if(x-1>=0 && !vis[x-1][y] && isPresent(board, x-1, y, word, index+1, vis)) return true;
        if(y-1>=0 && !vis[x][y-1] && isPresent(board, x, y-1, word, index+1, vis)) return true;
        if(x+1<board.size() && !vis[x+1][y] && isPresent(board, x+1, y, word, index+1, vis)) return true;
        if(y+1<board[0].size() && !vis[x][y+1] && isPresent(board, x, y+1, word, index+1, vis)) return true;
        vis[x][y] = false;
        return false;
    } 
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), false));
                if(isPresent(board, i, j, word, 0, vis)) return true;
            }
        }
        return false;
    }
};