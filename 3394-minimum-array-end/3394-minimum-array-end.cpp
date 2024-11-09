class Solution {
public:
    long long minEnd(int n, int x) {
        // Start with the first element as x
        long long current = x;
        
        // Construct the strictly increasing sequence
        for (int i = 1; i < n; ++i) {
            // Increment by 1 to ensure strict increase
            current += 1;
            
            // Ensure that current still keeps AND property with x
            current |= x; // Add bits of x if not already present
        }
        
        return current;
    }
};
