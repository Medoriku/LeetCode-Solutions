class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4)
            return result; // If fewer than 4 elements, no solution

        sort(nums.begin(), nums.end()); // Sort array for two-pointer technique

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate values
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate values
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long newTarget = (long long)target - nums[i] -
                                      nums[j]; // Avoid integer overflow
                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[left] + nums[right];

                    if (sum == newTarget) {
                        result.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    } else if (sum < newTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
