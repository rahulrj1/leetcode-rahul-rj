class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rowMin(n, 1e6);
        vector<int> colMax(m, 0);
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                rowMin[i] = min(rowMin[i], matrix[i][j]), 
                colMax[j] = max(colMax[j], matrix[i][j]);
        
        vector<int> res;
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++)
                if(rowMin[i] == matrix[i][j] && colMax[j] == matrix[i][j])
                    res.push_back(matrix[i][j]);
        
        return res;
    }
};