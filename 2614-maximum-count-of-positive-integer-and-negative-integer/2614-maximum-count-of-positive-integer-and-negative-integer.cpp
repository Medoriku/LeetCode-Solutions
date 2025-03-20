class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = lower_bound(nums.begin(), nums.end(), 0) -
                       nums.begin(); // Count of negatives
        int posCount = nums.end() - upper_bound(nums.begin(), nums.end(),
                                                0); // Count of positives
        return max(negCount, posCount);
    }
};