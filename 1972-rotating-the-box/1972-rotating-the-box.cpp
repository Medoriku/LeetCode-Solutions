class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();    // Number of rows
        int n = box[0].size(); // Number of columns
        
        // Step 1: Simulate gravity for each row
        for (int i = 0; i < m; i++) {
            int emptyPos = n - 1; // Start from the rightmost position
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    emptyPos = j - 1; // Obstacle blocks stones from falling further
                } else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][emptyPos]);
                    emptyPos--;
                }
            }
        }
        
        // Step 2: Rotate the box 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m)); // Resultant rotated box
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }
        
        return rotatedBox;
    }
};
