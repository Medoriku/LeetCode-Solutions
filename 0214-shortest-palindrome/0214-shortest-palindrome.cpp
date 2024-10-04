class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Create a new string which is `s + '#' + reversed(s)`
        string new_s = s + "#" + rev_s;
        
        // Compute the KMP table (longest prefix that is also suffix)
        vector<int> lps(new_s.size(), 0); // Longest Prefix Suffix array
        
        for (int i = 1; i < new_s.size(); ++i) {
            int j = lps[i - 1];  // Start by comparing with the previous prefix length
            while (j > 0 && new_s[i] != new_s[j]) {
                j = lps[j - 1];  // Follow the fallback in the LPS array
            }
            if (new_s[i] == new_s[j]) {
                ++j;
            }
            lps[i] = j;
        }
        
        // The length of the longest palindromic prefix in `s` is lps.back()
        int longest_palindrome_len = lps.back();
        
        // Take the non-palindromic suffix, reverse it and add it to the front
        string to_add = rev_s.substr(0, s.size() - longest_palindrome_len);
        return to_add + s;
    }
};
