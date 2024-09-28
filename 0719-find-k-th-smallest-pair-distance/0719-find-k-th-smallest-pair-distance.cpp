class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Sort the nums array
        sort(nums.begin(), nums.end());
        
        int left = 0; // Minimum possible distance
        int right = nums[nums.size() - 1] - nums[0]; // Maximum possible distance
        
        // Binary search for the smallest distance
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Count the number of pairs with distance <= mid
            int count = countPairs(nums, mid);
            
            if (count >= k) {
                right = mid; // Try to find a smaller distance
            } else {
                left = mid + 1; // Increase the distance
            }
        }
        
        return left;
    }

private:
    // Helper function to count pairs with distance <= mid
    int countPairs(const vector<int>& nums, int mid) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            // Use binary search or two-pointer technique to find the number of pairs
            while (j < n && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += (j - i - 1); // Pairs (i, j) where distance <= mid
        }
        
        return count;
    }
};
