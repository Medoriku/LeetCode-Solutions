
class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int lo = std::lower_bound(nums.begin() + i + 1, nums.end(),
                                      lower - nums[i]) -
                     nums.begin();
            int hi = std::upper_bound(nums.begin() + i + 1, nums.end(),
                                      upper - nums[i]) -
                     nums.begin();
            count += (hi - lo);
        }

        return count;
    }
};
