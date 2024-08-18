class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0; // Start index of the longest palindromic substring
        int end = 0;   // End index of the longest palindromic substring

        for (int i = 0; i < s.length(); ++i) {
            int len1 = expandAroundCenter(s, i, i);      // Check for odd-length palindrome
            int len2 = expandAroundCenter(s, i, i + 1);  // Check for even-length palindrome
            int len = max(len1, len2);                   // Get the maximum length

            if (len > end - start) {
                start = i - (len - 1) / 2;  // Update start index
                end = i + len / 2;          // Update end index
            }
        }

        return s.substr(start, end - start + 1); // Return the longest palindrome substring
    }

private:
    int expandAroundCenter(const string &s, int left, int right) {
        // Expand around the center while the characters are equal
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Return the length of the palindrome
    }
};
