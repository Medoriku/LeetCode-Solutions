class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] is the minimum height for placing first i books
        dp[0] = 0; // no books, no height
        
        for (int i = 1; i <= n; ++i) {
            int width = 0, maxHeight = 0;
            // Place books[i-1] on a new shelf and consider previous books
            for (int j = i; j > 0; --j) {
                width += books[j - 1][0];
                if (width > shelfWidth) break; // Exceeding shelf width, stop here
                maxHeight = max(maxHeight, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxHeight);
            }
        }
        
        return dp[n];
    }
};