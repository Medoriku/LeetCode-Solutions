
class Solution {
public:
    int takeCharacters(string s, int k) {
        // Step 1: Count total occurrences of 'a', 'b', 'c'
        vector<int> total(3, 0); // total[0]: 'a', total[1]: 'b', total[2]: 'c'
        for (char c : s) {
            total[c - 'a']++;
        }

        // Step 2: Check feasibility
        for (int count : total) {
            if (count < k) return -1; // Not possible
        }

        // Step 3: Sliding window
        int n = s.size();
        int maxLength = 0; // Length of the largest valid subarray
        vector<int> current(3, 0); // current counts of 'a', 'b', 'c'
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Expand the window
            current[s[right] - 'a']++;

            // Shrink the window if it violates the condition
            while (current[0] > total[0] - k || current[1] > total[1] - k || current[2] > total[2] - k) {
                current[s[left] - 'a']--;
                left++;
            }

            // Update the max length of valid subarray
            maxLength = max(maxLength, right - left + 1);
        }

        // Step 4: Compute the result
        return n - maxLength;
    }
};
