class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        
        // Traverse both strings
        while (i < n || j < n) {
            // Skip blanks in start
            while (i < n && start[i] == '_') i++;
            // Skip blanks in target
            while (j < n && target[j] == '_') j++;
            
            // If both reach the end, return true
            if (i == n && j == n) return true;
            
            // If one reaches the end before the other, return false
            if (i == n || j == n) return false;
            
            // Characters must match
            if (start[i] != target[j]) return false;
            
            // Check movement constraints
            if (start[i] == 'L' && i < j) return false; // 'L' can only move left
            if (start[i] == 'R' && i > j) return false; // 'R' can only move right
            
            // Move both pointers
            i++;
            j++;
        }
        
        return true;
    }
};
