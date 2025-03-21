
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Validate dimensions
        if (original.size() != m * n) {
            return {};
        }

        // Initialize 2D array
        vector<vector<int>> result(m, vector<int>(n));

        // Fill the 2D array
        for (int i = 0; i < original.size(); ++i) {
            result[i / n][i % n] = original[i];
        }

        return result;
    }
};
