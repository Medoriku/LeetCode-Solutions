class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;  // To store the unique substrings
        return backtrack(s, 0, seen);  // Start backtracking from the 0th index
    }
    
private:
    // Backtracking function to split the string and count unique substrings
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.size()) {
            return 0;  // If we have processed the whole string, return 0 (base case)
        }
        
        int maxCount = 0;
        
        // Try splitting the string into substrings starting from the current index
        for (int i = start; i < s.size(); ++i) {
            string current = s.substr(start, i - start + 1);  // Get the substring [start, i]
            
            if (seen.find(current) == seen.end()) {  // If the substring is unique
                seen.insert(current);  // Add it to the set of unique substrings
                
                // Recurse on the remaining part of the string and get the count
                int result = 1 + backtrack(s, i + 1, seen);
                maxCount = max(maxCount, result);  // Update the maximum count
                
                seen.erase(current);  // Backtrack: remove the substring from the set
            }
        }
        
        return maxCount;
    }
};
