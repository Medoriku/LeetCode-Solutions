class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            // If characters match, move both pointers
            if (s[i] == t[j]) {
                i++;
            }
            // Always move pointer for t
            j++;
        }
        // Check if we have matched all characters of s
        return i == s.size();
    }
};
