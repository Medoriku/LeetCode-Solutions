class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Convert banned array into a set for fast lookup
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        int currentSum = 0, count = 0;

        // Iterate through the range [1, n]
        for (int i = 1; i <= n; ++i) {
            // Skip if the number is in the banned set
            if (bannedSet.count(i))
                continue;

            // Check if adding the current number exceeds maxSum
            if (currentSum + i > maxSum)
                break;

            // Otherwise, include the number
            currentSum += i;
            count++;
        }

        return count;
    }
};
