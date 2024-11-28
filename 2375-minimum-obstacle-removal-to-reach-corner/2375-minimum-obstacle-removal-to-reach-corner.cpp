class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Directions for moving in 4 directions: up, down, left, right
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Priority queue: (obstacles_removed, (row, col))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        // Distance matrix to track the minimum obstacles removed to reach each cell
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        
        // Start from the top-left corner
        pq.push({0, {0, 0}});
        distance[0][0] = 0;
        
        while (!pq.empty()) {
            auto [current_obstacles, cell] = pq.top();
            pq.pop();
            
            int row = cell.first, col = cell.second;
            
            // If we've reached the bottom-right corner, return the result
            if (row == m - 1 && col == n - 1) {
                return current_obstacles;
            }
            
            // Process neighbors
            for (auto [dx, dy] : directions) {
                int new_row = row + dx, new_col = col + dy;
                
                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
                    int new_obstacles = current_obstacles + grid[new_row][new_col];
                    
                    // Update distance if a shorter path is found
                    if (new_obstacles < distance[new_row][new_col]) {
                        distance[new_row][new_col] = new_obstacles;
                        pq.push({new_obstacles, {new_row, new_col}});
                    }
                }
            }
        }
        
        return -1; // This line will never be reached as a path is guaranteed.
    }
};
