class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Initialize the prefix to be the first string in the array
        std::string prefix = strs[0];
        // Iterate over the rest of the strings in the array
        for (size_t i = 1; i < strs.size(); ++i) {
            // Compare the current prefix with each string
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by removing the last character
                prefix = prefix.substr(0, prefix.size() - 1);
                // If the prefix becomes empty, return an empty string
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        return prefix;  // Return the longest common prefix
    }
};