class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int>
            countMap; // To store normalized rows and their counts
        int maxCount = 0;

        for (const auto& row : matrix) {
            string normalized = ""; // Normalized form of the row
            for (int j = 0; j < row.size(); j++) {
                // Flip the row based on the first element
                normalized += (row[j] == row[0] ? '0' : '1');
            }
            countMap[normalized]++;
            maxCount = max(maxCount, countMap[normalized]);
        }

        return maxCount;
    }
};
