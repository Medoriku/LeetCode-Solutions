
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Boundaries
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        // Start filling in the spiral order
        ListNode* current = head;
        while (current) {
            // Traverse from left to right
            for (int i = left; i <= right && current; i++) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            top++;  // Move the top boundary down
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom && current; i++) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--;  // Move the right boundary left
            
            // Traverse from right to left
            for (int i = right; i >= left && current; i--) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            bottom--;  // Move the bottom boundary up
            
            // Traverse from bottom to top
            for (int i = bottom; i >= top && current; i--) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            left++;  // Move the left boundary right
        }
        
        return matrix;
    }
};
