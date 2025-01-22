class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        // Initialize the height matrix
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q; // Queue for BFS

        // Start with all water cells and assign them height 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions: North, East, South, West
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform BFS to propagate heights
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Check if the new coordinates are valid
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    height[nx][ny] == -1) {
                    // Assign height to the neighboring land cell
                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return height;
    }
};
