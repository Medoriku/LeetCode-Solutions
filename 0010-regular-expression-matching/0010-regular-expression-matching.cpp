class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // dp[i][j] will be true if first i characters of s match the first j characters of p
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty string and empty pattern match
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c*, etc.
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // If characters match or pattern has '.', carry over the previous match
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' can either match zero of the previous character or one or more
                    dp[i][j] = dp[i][j - 2]; // '*' matches zero occurrences
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // '*' matches one or more occurrences
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};
