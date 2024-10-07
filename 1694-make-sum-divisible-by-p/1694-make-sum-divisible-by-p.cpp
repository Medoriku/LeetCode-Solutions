class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total_sum = 0;
        
        // Step 1: Calculate total sum modulo p
        for (int num : nums) {
            total_sum = (total_sum + num) % p;
        }
        
        // If total sum is already divisible by p, no need to remove anything
        if (total_sum == 0) return 0;
        
        // Step 2: We need to find a subarray whose sum modulo p is `total_sum`
        int target = total_sum;
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; // We can start from the beginning if needed
        int prefix_sum = 0;
        int min_len = n; // Start with the maximum possible length
        
        for (int i = 0; i < n; ++i) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            
            // Find the value we need to remove to make the remaining sum divisible by p
            int need = (prefix_sum - target + p) % p;
            
            // Check if we've seen this prefix before
            if (prefix_map.find(need) != prefix_map.end()) {
                int subarray_len = i - prefix_map[need];
                min_len = min(min_len, subarray_len);
            }
            
            // Store the current prefix sum modulo and its index
            prefix_map[prefix_sum] = i;
        }
        
        // If we couldn't find any valid subarray, return -1
        return min_len == n ? -1 : min_len;
    }
};
