class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y) {
        for(int i=0; i<9; i++) {
            if(i!=x && board[i][y] == board[x][y]) return false;
            if(i!=y && board[x][i] == board[x][y]) return false;
        }
        int bx = x/3, by = y/3; bx *= 3; by *= 3;
        for(int i=0; i<3; i++) for(int j=0; j<3; j++) {
            if(bx+i == x && by+j == y) continue;
            if(board[bx+i][by+j] == board[x][y]) return false; 
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board.size(); j++) {
                if(board[i][j] != '.' && !isValid(board, i, j)) {return false;}
            } 
        }
        return true;
    }
};