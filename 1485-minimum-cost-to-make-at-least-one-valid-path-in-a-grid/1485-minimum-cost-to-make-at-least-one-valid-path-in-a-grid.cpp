class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(
            m, vector<int>(n, INT_MAX)); // Initialize cost grid
        deque<pair<int, int>> dq;        // 0-1 BFS queue

        // Directions: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Start from (0, 0)
        dq.push_front({0, 0});
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d].first;
                int ny = y + directions[d].second;
                int newCost =
                    cost[x][y] +
                    (grid[x][y] != d + 1); // Cost depends on matching sign

                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    if (grid[x][y] == d + 1) {
                        dq.push_front({nx, ny}); // Follow the arrow, no cost
                    } else {
                        dq.push_back({nx, ny}); // Modify the sign, cost = 1
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
