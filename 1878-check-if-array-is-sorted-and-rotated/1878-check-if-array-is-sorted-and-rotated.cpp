class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] >
                nums[(i + 1) % n]) { // Compare with next element (wrap around)
                count++;
            }
            if (count > 1)
                return false; // More than one drop → Not sorted & rotated
        }

        return true;
    }
};
