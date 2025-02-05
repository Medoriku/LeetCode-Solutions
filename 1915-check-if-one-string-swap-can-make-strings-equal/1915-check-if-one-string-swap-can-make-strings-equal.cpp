class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff; // Store indices where s1[i] != s2[i]

        // Identify differing positions
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        // Case 1: Strings are already equal
        if (diff.size() == 0)
            return true;

        // Case 2: Check if swapping two characters fixes the strings
        if (diff.size() == 2) {
            int i = diff[0], j = diff[1];
            return (s1[i] == s2[j] && s1[j] == s2[i]);
        }

        // Case 3: More than 2 differences, impossible to fix with one swap
        return false;
    }
};
