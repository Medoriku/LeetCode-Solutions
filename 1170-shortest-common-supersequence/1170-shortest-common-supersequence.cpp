class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();

        // Step 1: Compute LCS using DP
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Construct the SCS using the LCS table
        int i = m, j = n;
        string scs = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs += str1[i - 1]; // Common character from LCS
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs += str1[i - 1]; // Take character from str1
                i--;
            } else {
                scs += str2[j - 1]; // Take character from str2
                j--;
            }
        }

        // Add remaining characters from str1 and str2
        while (i > 0) {
            scs += str1[i - 1];
            i--;
        }
        while (j > 0) {
            scs += str2[j - 1];
            j--;
        }

        reverse(scs.begin(), scs.end()); // Since we built it backwards
        return scs;
    }
};
