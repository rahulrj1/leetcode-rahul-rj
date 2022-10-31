class Solution {
public:
    bool isToep(vector<vector<int>> &matrix, int i, int j) {
        if(i+1 >= matrix.size() || j+1 >= matrix[0].size()) return true;
        if(matrix[i+1][j+1] != matrix[i][j]) return false;
        return isToep(matrix, i+1, j+1);
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++) {
            if(!isToep(matrix, i, 0)) return false;
        }
        for(int j=1; j<matrix[0].size(); j++) {
            if(!isToep(matrix, 0, j)) return false;
        }
        return true;
    }
};