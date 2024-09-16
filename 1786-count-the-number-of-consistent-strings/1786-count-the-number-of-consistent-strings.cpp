class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set of allowed characters for fast lookup
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        
        int count = 0;  // Initialize a counter for consistent strings
        
        // Loop through each word in the words vector
        for (const string& word : words) {
            bool isConsistent = true;  // Assume the word is consistent
            
            // Check if each character in the word is allowed
            for (char c : word) {
                if (allowedSet.find(c) == allowedSet.end()) {
                    isConsistent = false;  // If any character is not allowed, mark it as inconsistent
                    break;  // No need to check further for this word
                }
            }
            
            // If the word is consistent, increment the counter
            if (isConsistent) {
                count++;
            }
        }
        
        // Return the total number of consistent strings
        return count;
    }
};
