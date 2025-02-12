class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxMap; // Stores max number for each digit sum
        int maxSum = -1;

        for (int num : nums) {
            int digitSum = sumOfDigits(num);
            if (maxMap.find(digitSum) != maxMap.end()) {
                maxSum = max(maxSum, maxMap[digitSum] + num);
            }
            maxMap[digitSum] = max(maxMap[digitSum], num);
        }

        return maxSum;
    }
};
