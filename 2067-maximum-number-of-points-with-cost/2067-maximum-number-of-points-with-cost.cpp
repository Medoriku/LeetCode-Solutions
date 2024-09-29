class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(); // number of rows
        int n = points[0].size(); // number of columns
        
        // Initialize dp to store maximum points achievable up to each row.
        vector<long long> dp(n, 0);
        
        // Start with the first row's points as the base case
        for (int j = 0; j < n; ++j) {
            dp[j] = points[0][j];
        }
        
        // Process each row
        for (int r = 1; r < m; ++r) {
            // Temporary dp to store the new row's maximums
            vector<long long> new_dp(n, 0);
            
            // Compute the prefix maximum array
            vector<long long> prefix(n, 0);
            prefix[0] = dp[0];
            for (int j = 1; j < n; ++j) {
                prefix[j] = max(prefix[j-1], dp[j] + j);
            }
            
            // Compute the suffix maximum array
            vector<long long> suffix(n, 0);
            suffix[n-1] = dp[n-1] - (n-1);
            for (int j = n-2; j >= 0; --j) {
                suffix[j] = max(suffix[j+1], dp[j] - j);
            }
            
            // Update new_dp using prefix and suffix
            for (int j = 0; j < n; ++j) {
                new_dp[j] = max(prefix[j] - j, suffix[j] + j) + points[r][j];
            }
            
            // Update dp with the new row's maximums
            dp = new_dp;
        }
        
        // The result is the maximum value in the last dp array
        return *max_element(dp.begin(), dp.end());
    }
};
