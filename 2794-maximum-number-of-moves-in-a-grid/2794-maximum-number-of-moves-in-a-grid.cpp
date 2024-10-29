class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // DP table to store the maximum moves starting from each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Traverse from the second last column back to the first
        for (int col = n - 2; col >= 0; --col) {
            for (int row = 0; row < m; ++row) {
                int max_moves = 0;

                // Check right cell
                if (grid[row][col] < grid[row][col + 1]) {
                    max_moves = max(max_moves, dp[row][col + 1] + 1);
                }

                // Check up-right cell
                if (row > 0 && grid[row][col] < grid[row - 1][col + 1]) {
                    max_moves = max(max_moves, dp[row - 1][col + 1] + 1);
                }

                // Check down-right cell
                if (row < m - 1 && grid[row][col] < grid[row + 1][col + 1]) {
                    max_moves = max(max_moves, dp[row + 1][col + 1] + 1);
                }

                dp[row][col] = max_moves;
            }
        }

        // Get the maximum moves from any cell in the first column
        int result = 0;
        for (int row = 0; row < m; ++row) {
            result = max(result, dp[row][0]);
        }

        return result;
    }
};
