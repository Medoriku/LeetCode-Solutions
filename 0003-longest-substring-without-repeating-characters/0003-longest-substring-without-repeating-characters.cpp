class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string nonrep;  // Stores the current substring without repeating characters
        int maxLength = 0;  // Stores the maximum length of substring found

        for (int i = 0; i < s.length(); ++i) {
            // If the character is not in the current substring, add it
            if (nonrep.find(s[i]) == string::npos) {
                nonrep.push_back(s[i]);
            } 
            else {
                // If the character is repeating, update maxLength
                maxLength = max(maxLength, static_cast<int>(nonrep.length()));

                // Find the first occurrence of s[i] in nonrep and erase the substring before and including it
                nonrep.erase(0, nonrep.find(s[i]) + 1);

                // Add the current character to the substring after removing the repetition
                nonrep.push_back(s[i]);
            }
        }

        // After the loop, ensure to compare the length of the last processed substring
        maxLength = max(maxLength, static_cast<int>(nonrep.length()));

        return maxLength;
    }
};
