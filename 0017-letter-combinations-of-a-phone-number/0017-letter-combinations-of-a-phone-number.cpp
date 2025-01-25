class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // If the input string is empty, return an empty result
        if (digits.empty()) return {};
        
        // Mapping from digits to corresponding letters
        vector<string> digitToLetters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        // Result to store the combinations
        vector<string> result;
        
        // Helper function to perform backtracking
        function<void(int, string)> backtrack = [&](int index, string current) {
            // If we've reached the end of the digits, add the current combination to the result
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
            
            // Get the letters for the current digit
            string letters = digitToLetters[digits[index] - '0'];
            
            // Try all possible letters for the current digit
            for (char letter : letters) {
                backtrack(index + 1, current + letter);
            }
        };
        
        // Start the backtracking process from index 0 with an empty string
        backtrack(0, "");
        
        return result;
    }
};
