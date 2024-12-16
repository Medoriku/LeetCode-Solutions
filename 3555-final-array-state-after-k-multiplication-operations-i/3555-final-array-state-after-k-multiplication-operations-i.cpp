class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k > 0) {
            // Find the index of the minimum value
            int minIndex = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            // Multiply the minimum value by the multiplier
            nums[minIndex] *= multiplier;
            // Decrease the operation count
            --k;
        }
        return nums;
    }
};
