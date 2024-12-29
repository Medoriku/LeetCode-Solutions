class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();

        // Step 1: Precompute character frequencies in each column of words
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[j][word[j] - 'a']++;
            }
        }

        // Step 2: DP array to store the number of ways
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));

        // Base case: There's 1 way to form an empty target
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }

        // Step 3: Fill the DP table
        for (int i = 1; i <= m; ++i) {     // For each character in target
            for (int j = 1; j <= n; ++j) { // For each column in words
                dp[i][j] = dp[i][j - 1];   // Skip this column
                if (freq[j - 1][target[i - 1] - 'a'] > 0) {
                    dp[i][j] +=
                        dp[i - 1][j - 1] * freq[j - 1][target[i - 1] - 'a'];
                    dp[i][j] %= MOD; // Take modulo to avoid overflow
                }
            }
        }

        // Step 4: Return the number of ways to form the entire target using all
        // columns
        return dp[m][n];
    }
};
