class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k > n)
            return 0; // Edge case: No valid groups if k is larger than array
                      // size

        int count = 0;
        bool isAlternating = true;

        // Check the first window of size k
        for (int j = 1; j < k; j++) {
            if (colors[j] == colors[j - 1]) {
                isAlternating = false;
                break;
            }
        }
        if (isAlternating)
            count++;

        // Sliding window check for remaining positions
        for (int i = 1; i < n; i++) {
            int prevIdx = (i - 1 + n) % n; // Previous start of window
            int newIdx = (i + k - 1) % n;  // New element to check

            // If the old window was alternating, only check the new transition
            if (isAlternating) {
                if (colors[newIdx] == colors[(newIdx - 1 + n) % n]) {
                    isAlternating = false;
                }
            }
            // If the old window was not alternating, recheck the entire window
            else {
                isAlternating = true;
                for (int j = 1; j < k; j++) {
                    int currIdx = (i + j) % n;
                    int prevIdx = (i + j - 1) % n;
                    if (colors[currIdx] == colors[prevIdx]) {
                        isAlternating = false;
                        break;
                    }
                }
            }
            if (isAlternating)
                count++;
        }

        return count;
    }
};
