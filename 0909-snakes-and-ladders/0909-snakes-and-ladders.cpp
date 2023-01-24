class Solution {
public:
    vector<int> findXY(int dest, int n) {
        int x = n-1-((dest-1)/n);
        int y = (n-1-x)&1 ? n-1-((dest-1)%n) : (dest-1)%n;
        return {x, y};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<vector<int>> q;
        
        vector<int> lookup((n*n) + 1, 500);
        q.push({1, 0});
        while(!q.empty()) {
            auto z = q.front(); q.pop();
            if(lookup[z[0]] <= z[1]) continue;
            lookup[z[0]] = z[1];
            
            for(int i=1; i<=6; i++) {
                int dest = z[0]+i; 
                if(dest > n*n) break;
                vector<int> v = findXY(dest, n);
                int x = v[0], y = v[1];
                
                if(board[x][y] != -1) dest = board[x][y];
                
                if(lookup[dest] > z[1]+1) q.push({dest, z[1]+1});
            }
        }
        
        return lookup[n*n] == 500 ? -1 : lookup[n*n];
    }
};