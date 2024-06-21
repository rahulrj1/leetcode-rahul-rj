class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix[0].size(), res = 0;
        vector<int> row(n, 0);
        for(vector<int> &matrixRow: matrix) {
            for(int i=0; i<n; i++) row[i] = matrixRow[i] == 0 ? 0 : row[i] + matrixRow[i];
            vector<int> temp = row;
            sort(temp.rbegin(), temp.rend());
            for(int i=0; i<n; i++) res = max(res, temp[i]*(i+1));
        }
        return res;
    }
};