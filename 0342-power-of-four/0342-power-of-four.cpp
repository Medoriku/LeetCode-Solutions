class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;  // 0 and negative numbers cannot be powers of four
        }
        while (n % 4 == 0) {  // While n is divisible by 4
            n /= 4;  // Divide n by 4
        }
        return n == 1;  // If n is reduced to 1, it was a power of 4
    }
};