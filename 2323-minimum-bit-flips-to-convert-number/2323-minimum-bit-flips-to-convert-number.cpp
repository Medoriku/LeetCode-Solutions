class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR the two numbers to find the differing bits
        int xorResult = start ^ goal;
        
        // Count the number of 1s using Brian Kernighan's Algorithm
        int bitFlips = 0;
        while (xorResult > 0) {
            xorResult &= (xorResult - 1);  // Clears the lowest set bit
            bitFlips++;
        }
        
        return bitFlips;
    }
};
