class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // Initialize the min and max with the first array's values
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int result = 0;

        // Iterate over the arrays starting from the second one
        for (int i = 1; i < arrays.size(); ++i) {
            // Calculate the possible maximum distances using the current array's first and last elements
            result = max(result, abs(arrays[i].back() - minVal));  // Compare current array's max with global min
            result = max(result, abs(maxVal - arrays[i][0]));      // Compare global max with current array's min

            // Update global min and max
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }

        return result;
    }
};
