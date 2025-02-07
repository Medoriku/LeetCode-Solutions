class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; // Maps ball index to its color
        unordered_set<int> distinctColors; // Tracks unique colors
        vector<int> result;

        for (auto& q : queries) {
            int ball = q[0], color = q[1];

            // If ball already has a color
            if (ballColor.count(ball)) {
                int prevColor = ballColor[ball];

                // Check if removing previous color reduces distinct colors
                bool shouldErase = true;
                for (auto& [key, val] : ballColor) {
                    if (val == prevColor && key != ball) {
                        shouldErase = false;
                        break;
                    }
                }

                if (shouldErase) {
                    distinctColors.erase(prevColor);
                }
            }

            // Assign the new color
            ballColor[ball] = color;
            distinctColors.insert(color);

            // Store the number of distinct colors
            result.push_back(distinctColors.size());
        }

        return result;
    }
};
