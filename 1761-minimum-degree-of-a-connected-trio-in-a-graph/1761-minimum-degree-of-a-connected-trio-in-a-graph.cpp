class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);
        vector<vector<bool>> z(n, vector<bool> (n, false));
        for(vector<int>& edge: edges) {
            int i = edge[0]-1, j = edge[1]-1;
            degree[i]++, degree[j]++, z[i][j]=true, z[j][i]=true;
        }
        
        int res = 1e6;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if(z[i][j] && z[j][k] && z[i][k]) {
                        res = min(res, degree[i] + degree[j] + degree[k] - 6);
                    }
                } 
            }
        }
        return res == 1e6 ? -1 : res;
    }
};