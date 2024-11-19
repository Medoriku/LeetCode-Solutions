
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> seen;
        long long currentSum = 0, maxSum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currentSum -= nums[left];
                ++left;
            }

            seen.insert(nums[right]);
            currentSum += nums[right];

            // Check if the window size equals k
            if (right - left + 1 == k) {
                maxSum = max(maxSum, currentSum);

                // Slide the window by removing the leftmost element
                seen.erase(nums[left]);
                currentSum -= nums[left];
                ++left;
            }
        }

        return maxSum;
    }
};
