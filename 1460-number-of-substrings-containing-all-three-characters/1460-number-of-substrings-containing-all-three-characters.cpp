class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0}; // Stores frequency of 'a', 'b', 'c'
        int left = 0, result = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++; // Update frequency

            // Ensure all three characters are present in the window
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += s.size() - right; // Add all valid substrings
                count[s[left] - 'a']--;     // Shrink the window
                left++;
            }
        }

        return result;
    }
};
