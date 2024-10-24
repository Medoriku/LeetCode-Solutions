class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n); // Array to store the ugly numbers
        ugly[0] = 1; // The first ugly number is 1
        int i2 = 0, i3 = 0, i5 = 0; // Pointers for 2, 3, 5
        
        // Initial multiples of 2, 3, and 5
        int next_2 = 2;
        int next_3 = 3;
        int next_5 = 5;
        
        for (int i = 1; i < n; ++i) {
            // Next ugly number is the minimum of next_2, next_3, next_5
            int next_ugly = min(next_2, min(next_3, next_5));
            ugly[i] = next_ugly;
            
            // Update the pointer and value for the chosen factor
            if (next_ugly == next_2) {
                i2++;
                next_2 = ugly[i2] * 2;
            }
            if (next_ugly == next_3) {
                i3++;
                next_3 = ugly[i3] * 3;
            }
            if (next_ugly == next_5) {
                i5++;
                next_5 = ugly[i5] * 5;
            }
        }
        
        return ugly[n - 1]; // Return the nth ugly number
    }
};
