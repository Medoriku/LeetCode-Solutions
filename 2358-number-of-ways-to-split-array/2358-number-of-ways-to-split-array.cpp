class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num; // Compute total sum
        }

        long long prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size() - 1;
             ++i) {               // Loop until the second last index
            prefixSum += nums[i]; // Compute prefix sum
            if (prefixSum >= totalSum - prefixSum) { // Check the condition
                ++count; // Increment count if condition is satisfied
            }
        }

        return count;
    }
};
