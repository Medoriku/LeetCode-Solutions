class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];     // Maximum sum of an ascending subarray
        int currentSum = nums[0]; // Current sum of an ascending subarray

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i]; // Extend the subarray
            } else {
                currentSum = nums[i]; // Start a new subarray
            }
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
