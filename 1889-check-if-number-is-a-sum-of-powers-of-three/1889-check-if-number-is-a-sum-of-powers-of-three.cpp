class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return false; // If remainder is 2, it cannot be expressed as sum of distinct powers of 3
            n /= 3; // Move to the next higher power
        }
        return true; // If we never encountered a '2', return true
    }
};
