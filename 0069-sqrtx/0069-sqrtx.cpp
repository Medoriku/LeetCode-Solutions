class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x; // Handle edge cases for 0 and 1

        int left = 1, right = x, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if mid * mid is less than or equal to x
            if (mid <= x / mid) {
                result = mid; // Update result to mid, as it's a valid candidate
                left = mid + 1; // Try for a larger value
            } else {
                right = mid - 1; // Try for a smaller value
            }
        }

        return result;
    }
};
