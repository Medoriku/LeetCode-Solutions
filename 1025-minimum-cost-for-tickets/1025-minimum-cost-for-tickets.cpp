class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int lastDay = days.back();      // Last travel day
        vector<int> dp(lastDay + 1, 0); // DP array up to the last day
        unordered_set<int> travelDays(days.begin(),
                                      days.end()); // Travel days as a set

        for (int i = 1; i <= lastDay; ++i) {
            if (!travelDays.count(i)) {
                dp[i] = dp[i - 1]; // If not a travel day, cost is the same as
                                   // the previous day
            } else {
                dp[i] = dp[i - 1] + costs[0];                     // 1-day pass
                dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]); // 7-day pass
                dp[i] =
                    min(dp[i], dp[max(0, i - 30)] + costs[2]); // 30-day pass
            }
        }

        return dp[lastDay]; // Minimum cost to cover all travel days
    }
};
