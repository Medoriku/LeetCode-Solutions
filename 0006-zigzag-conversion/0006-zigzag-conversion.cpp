class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if numRows is 1, return the original string as no zigzag happens
        if (numRows == 1) return s;
        
        // Create an array of strings for each row
        vector<string> rows(min(numRows, int(s.size())));
        
        int currRow = 0;
        bool goingDown = false;

        // Traverse through each character in the string
        for (char c : s) {
            rows[currRow] += c;  // Add character to the current row

            // If we're at the first or last row, reverse direction
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row depending on the direction
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows to get the final result
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};
