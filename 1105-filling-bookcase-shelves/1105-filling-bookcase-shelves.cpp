class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1);
        dp[0] = 0; // dp[i] represents height when only first i books are present
        
        for(int i=1; i<=n; i++) {
            // put the (i-1)th book on a new shelf
            int shelfHeight = books[i-1][1];
            int remainingThickness = shelfWidth - books[i-1][0];
            dp[i] = dp[i-1] + shelfHeight;
            
            // put (j-1)th to (i-1)th books on the same shelf
            int j = i-1;
            while(j>0 && remainingThickness - books[j-1][0] >= 0) {
                remainingThickness -= books[j-1][0];
                shelfHeight = max(shelfHeight, books[j-1][1]);
                
                dp[i] = min(dp[i], dp[j-1] + shelfHeight);
                j--;
            }
        }
        return dp[n];
    }
};