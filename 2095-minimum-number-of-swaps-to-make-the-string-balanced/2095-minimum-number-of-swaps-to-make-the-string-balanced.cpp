class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0, maxImbalance = 0;

        // Traverse the string
        for (char c : s) {
            if (c == '[') {
                // Opening bracket reduces imbalance
                imbalance--;
            } else {
                // Closing bracket increases imbalance
                imbalance++;
            }

            // Record the maximum imbalance
            maxImbalance = max(maxImbalance, imbalance);
        }

        // We only need half of the maximum imbalance as each swap fixes 2 brackets
        return (maxImbalance + 1) / 2;
    }
};
