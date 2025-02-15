#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool canPartition(std::string s, int target, int index = 0,
                      int currentSum = 0) {
        if (index == s.size()) {
            return currentSum ==
                   target; // If we've used all digits and sum matches i
        }

        int num = 0;
        for (int j = index; j < s.size(); ++j) {
            num = num * 10 + (s[j] - '0'); // Form the number from substring

            if (currentSum + num > target)
                break; // Stop early if sum exceeds target

            if (canPartition(s, target, j + 1, currentSum + num))
                return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int total = 0;

        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            if (canPartition(std::to_string(square), i)) {
                total += square;
            }
        }

        return total;
    }
};
