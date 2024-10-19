class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case for n = 1
        if (n == 1) return '0';
        
        // Length of S_n is (2^n - 1)
        int length = (1 << n) - 1; // This is equivalent to 2^n - 1
        int mid = (length + 1) / 2; // Middle position
        
        // Check if k is the middle element
        if (k == mid) return '1';
        
        // If k is in the first half
        if (k < mid) {
            return findKthBit(n - 1, k); // Corresponds to S_{n-1}
        } else {
            // If k is in the second half, adjust k for the inverted part
            int newK = length - k + 1; // Reflecting k
            char bit = findKthBit(n - 1, newK); // Corresponds to reversed(inverted(S_{n-1}))
            return (bit == '0') ? '1' : '0'; // Invert the bit
        }
    }
};
