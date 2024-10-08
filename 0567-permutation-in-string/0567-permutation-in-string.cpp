class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        // Length of the strings
        int s1Length = s1.length();
        int s2Length = s2.length();

        // If s1 is longer than s2, a permutation cannot exist
        if (s1Length > s2Length) {
            return false;
        }

        // Create frequency count arrays for s1 and the current window in s2
        std::vector<int> s1Count(26, 0);
        std::vector<int> s2Count(26, 0);

        // Fill the frequency count for s1 and the first window of s2
        for (int i = 0; i < s1Length; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Compare frequency arrays
        if (s1Count == s2Count) {
            return true;
        }

        // Slide the window over s2
        for (int i = s1Length; i < s2Length; i++) {
            // Add the next character in s2 to the window
            s2Count[s2[i] - 'a']++;
            // Remove the first character of the previous window
            s2Count[s2[i - s1Length] - 'a']--;

            // Compare frequency arrays
            if (s1Count == s2Count) {
                return true;
            }
        }

        return false;
    }
};