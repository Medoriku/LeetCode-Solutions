class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR the two numbers to find the differing bits
        int xorResult = start ^ goal;
        
        // Count the number of 1s in xorResult
        int bitFlips = 0;
        
        // Count the 1s using a loop
        while (xorResult > 0) {
            bitFlips += xorResult & 1;  // Check if the last bit is 1
            xorResult >>= 1;  // Right shift to check the next bit
        }
        
        return bitFlips;
    }
};
