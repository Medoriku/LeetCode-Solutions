class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        int spaceIndex = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            // If we are at an index where a space needs to be added
            if (spaceIndex < spaces.size() && spaces[spaceIndex] == i) {
                result += " ";  // Add a space at the correct position
                ++spaceIndex;   // Move to the next space index
            }
            result += s[i];  // Add the current character to the result string
        }
        
        return result;
    }
};