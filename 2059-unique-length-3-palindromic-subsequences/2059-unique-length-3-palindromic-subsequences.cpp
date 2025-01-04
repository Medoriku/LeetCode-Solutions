class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Array to store first and last occurrences of each character
        vector<int> first(26, -1), last(26, -1);

        // Populate the first and last occurrence arrays
        for (int i = 0; i < s.size(); ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i; // Set the first occurrence
            }
            last[s[i] - 'a'] = i; // Continuously update the last occurrence
        }

        int count = 0;

        // Iterate over each character in the alphabet
        for (int c = 0; c < 26; ++c) {
            if (first[c] != -1 && last[c] > first[c]) {
                // Use a set to collect unique characters between first and last
                // occurrence
                unordered_set<char> uniqueChars;
                for (int i = first[c] + 1; i < last[c]; ++i) {
                    uniqueChars.insert(s[i]);
                }
                // Add the number of unique characters to the count
                count += uniqueChars.size();
            }
        }

        return count;
    }
};
