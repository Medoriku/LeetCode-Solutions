class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n + 1, 0);
        
        // Step 1: Compute suffix sums
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Step 2: Initialize DP table
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Step 3: Fill DP table in reverse order
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                    dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                }
            }
        }

        // Step 4: Return the result
        return dp[0][1];
    }
};
