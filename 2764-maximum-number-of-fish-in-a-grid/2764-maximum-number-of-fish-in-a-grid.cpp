class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        // Directions for moving in 4 directions (up, down, left, right)
        vector<int> dirs = {0, 1, 0, -1, 1, 0, -1, 0};

        // Helper function for DFS
        function<int(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) {
                return 0;
            }

            int fish = grid[r][c]; // Get the number of fish at this cell
            grid[r][c] = 0;        // Mark this cell as visited

            // Explore 4 neighboring cells
            for (int i = 0; i < 4; i++) {
                fish += dfs(r + dirs[i], c + dirs[i + 4]);
            }

            return fish;
        };

        // Traverse the grid and apply DFS from each water cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(i, j));
                }
            }
        }

        return maxFish;
    }
};
