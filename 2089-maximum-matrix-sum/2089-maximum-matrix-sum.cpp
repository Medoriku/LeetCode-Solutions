class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sumAbs = 0;  // Total sum of absolute values
        int minAbs = INT_MAX; // Smallest absolute value
        int negativeCount = 0; // Count of negative numbers
        
        // Iterate through the matrix
        for (const auto& row : matrix) {
            for (int val : row) {
                sumAbs += abs(val);           // Add absolute value to the total sum
                minAbs = min(minAbs, abs(val)); // Update the minimum absolute value
                if (val < 0) negativeCount++;  // Count negatives
            }
        }
        
        // If the count of negatives is odd, adjust the sum
        if (negativeCount % 2 != 0) {
            sumAbs -= 2 * minAbs;
        }
        
        return sumAbs;
    }
};
