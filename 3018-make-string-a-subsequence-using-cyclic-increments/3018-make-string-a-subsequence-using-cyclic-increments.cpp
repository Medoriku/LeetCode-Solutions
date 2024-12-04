class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0; // Pointers for str1 and str2
        int n = str1.size(), m = str2.size();

        while (i < n && j < m) {
            char currentChar = str1[i];
            char nextChar = (currentChar - 'a' + 1) % 26 +
                            'a'; // Calculate cyclic increment

            // Check if current character in str1 matches or can be incremented
            // to match str2[j]
            if (currentChar == str2[j] || nextChar == str2[j]) {
                j++; // Move to the next character in str2
            }
            i++; // Move to the next character in str1
        }

        return j == m; // True if all characters in str2 are matched
    }
};
