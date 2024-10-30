class Solution {
public:
    int minimumMountainRemovals(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Compute LIS ending at each index
        std::vector<int> lis(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = std::max(lis[i], lis[j] + 1);
                }
            }
        }
        
        // Step 2: Compute LDS starting at each index
        std::vector<int> lds(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = std::max(lds[i], lds[j] + 1);
                }
            }
        }
        
        // Step 3: Find the minimum removals to make a mountain array
        int minRemovals = n;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) { // Valid peak
                int mountainLength = lis[i] + lds[i] - 1;
                minRemovals = std::min(minRemovals, n - mountainLength);
            }
        }
        
        return minRemovals;
    }
};
