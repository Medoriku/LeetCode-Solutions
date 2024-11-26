class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closestSum =
            nums[0] + nums[1] + nums[2]; // Initialize with the first triplet

        // Step 2: Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;

            // Step 3: Apply two-pointer technique
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Update the closest sum if the current one is closer
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // Adjust pointers
                if (currentSum < target) {
                    ++left; // Increase the sum
                } else if (currentSum > target) {
                    --right; // Decrease the sum
                } else {
                    // If the sum is exactly equal to the target, return it
                    // immediately
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};
