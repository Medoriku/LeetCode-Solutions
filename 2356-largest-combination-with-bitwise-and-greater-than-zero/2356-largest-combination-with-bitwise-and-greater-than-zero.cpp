class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // Array to count number of 1s in each bit position (up to 32 bits)
        int bitCount[32] = {0};
        
        // Count set bits at each position for all numbers
        for (int num : candidates) {
            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) {
                    bitCount[i]++;
                }
            }
        }
        
        // Find the maximum count across all bit positions
        int maxCombinationSize = 0;
        for (int i = 0; i < 32; ++i) {
            maxCombinationSize = max(maxCombinationSize, bitCount[i]);
        }
        
        return maxCombinationSize;
    }
};
