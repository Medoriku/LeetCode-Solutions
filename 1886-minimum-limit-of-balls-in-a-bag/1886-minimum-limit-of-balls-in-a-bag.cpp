class Solution {
public:
    bool canDivide(vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (int balls : nums) {
            // Calculate the number of operations needed for this bag
            operations += (balls - 1) / penalty;
            if (operations > maxOperations)
                return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canDivide(nums, maxOperations, mid)) {
                result = mid;   // Update the result with the feasible penalty
                high = mid - 1; // Try for a smaller penalty
            } else {
                low = mid + 1; // Try for a larger penalty
            }
        }

        return result;
    }
};
