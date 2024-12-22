class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long total = 0;
        int start = 0;
        std::multiset<int> window; // Keeps track of elements in the current window

        for (int end = 0; end < nums.size(); ++end) {
            // Add the current element to the multiset
            window.insert(nums[end]);

            // Check the max and min values in the window
            while (*window.rbegin() - *window.begin() > 2) {
                // Shrink the window from the left
                window.erase(window.find(nums[start]));
                start++;
            }

            // Count all subarrays ending at `end`
            total += (end - start + 1);
        }

        return total;
    }
};
