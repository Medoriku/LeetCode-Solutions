class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int rep_count = count(nums.begin(), nums.end(), nums[i]);
            if (rep_count > (nums.size() / 2)) {
                return nums[i];
            }
        }
        return 0;
    }
};