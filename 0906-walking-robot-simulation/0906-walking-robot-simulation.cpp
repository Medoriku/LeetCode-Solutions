class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0;  // Starting position
        int dir = 0;       // Starting direction (facing North)
        int maxDist = 0;
        
        // Use a set to store obstacles for O(1) lookup
        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        // Process each command
        for (int command : commands) {
            if (command == -2) {
                // Turn left (counterclockwise)
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                // Turn right (clockwise)
                dir = (dir + 1) % 4;
            } else {
                // Move forward 'command' steps
                for (int i = 0; i < command; ++i) {
                    int newX = x + directions[dir].first;
                    int newY = y + directions[dir].second;
                    
                    // Check if the new position is an obstacle
                    if (obstacleSet.count({newX, newY})) {
                        break;  // Stop moving if there's an obstacle
                    }

                    // Update the robot's position
                    x = newX;
                    y = newY;

                    // Calculate the squared distance from the origin
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;  // Return the maximum squared distance
    }
};
