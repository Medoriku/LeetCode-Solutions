class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        // Calculate prefix sums for both rows
        vector<long long> topPrefix(n, 0), bottomPrefix(n, 0);
        topPrefix[0] = grid[0][0];
        bottomPrefix[0] = grid[1][0];
        for (int i = 1; i < n; ++i) {
            topPrefix[i] = topPrefix[i - 1] + grid[0][i];
            bottomPrefix[i] = bottomPrefix[i - 1] + grid[1][i];
        }

        // Calculate suffix sums for the top row
        vector<long long> topSuffix(n, 0);
        topSuffix[n - 1] = grid[0][n - 1];
        for (int i = n - 2; i >= 0; --i) {
            topSuffix[i] = topSuffix[i + 1] + grid[0][i];
        }

        // Simulate the game
        long long result = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            // Points left for the second robot
            long long topPoints = (i + 1 < n) ? topSuffix[i + 1] : 0;
            long long bottomPoints = (i - 1 >= 0) ? bottomPrefix[i - 1] : 0;
            long long secondRobotPoints = max(topPoints, bottomPoints);

            // Minimize the maximum points for the second robot
            result = min(result, secondRobotPoints);
        }

        return result;
    }
};
