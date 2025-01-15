class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsNum2 = __builtin_popcount(num2); // Count set bits in num2
        int result = 0;

        // Step 1: Use num1's bits to match setBitsNum2
        for (int i = 31; i >= 0 && setBitsNum2 > 0; --i) {
            if (num1 & (1 << i)) {  // Check if the ith bit is set in num1
                result |= (1 << i); // Set the same bit in result
                --setBitsNum2;
            }
        }

        // Step 2: Add additional bits if setBitsNum2 > 0
        for (int i = 0; i <= 31 && setBitsNum2 > 0; ++i) {
            if (!(result &
                  (1 << i))) {      // Check if the ith bit is unset in result
                result |= (1 << i); // Set the ith bit in result
                --setBitsNum2;
            }
        }

        return result;
    }
};
