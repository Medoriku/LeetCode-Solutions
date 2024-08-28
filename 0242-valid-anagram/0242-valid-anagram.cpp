class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the strings are of different lengths, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        // Use a hash map to count the frequency of each character in 's'
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }

        // Decrease the frequency based on characters in 't'
        for (char c : t) {
            if (count[c] == 0) {
                return false; // More occurrences of this character in 't' than in 's'
            }
            count[c]--;
        }

        // If the map is balanced, the strings are anagrams
        return true;
    }
};
