class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int longest = 1;
        int inc_len = 1; // Length of the current increasing subarray
        int dec_len = 1; // Length of the current decreasing subarray

        // Traverse through the array
        for (int i = 1; i < n; i++) {
            // If increasing
            if (nums[i] > nums[i - 1]) {
                inc_len++;
                dec_len = 1; // Reset decreasing length
            }
            // If decreasing
            else if (nums[i] < nums[i - 1]) {
                dec_len++;
                inc_len = 1; // Reset increasing length
            }
            // If equal, both increasing and decreasing sequences reset
            else {
                inc_len = 1;
                dec_len = 1;
            }

            // Update the longest length
            longest = max(longest, max(inc_len, dec_len));
        }

        return longest;
    }
};
