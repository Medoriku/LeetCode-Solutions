class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxVal = (1 << maximumBit) - 1; // The maximum value for k in maximumBit bits
        int cumulativeXor = 0;
        
        // Compute the cumulative XOR for all elements in nums
        for (int num : nums) {
            cumulativeXor ^= num;
        }
        
        vector<int> result(nums.size());
        
        // For each query, calculate the maximum XOR value and then update cumulativeXor
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = cumulativeXor ^ maxVal; // Maximum XOR with the given cumulativeXor
            cumulativeXor ^= nums[nums.size() - 1 - i]; // Remove the last element from cumulative XOR
        }
        
        return result;
    }
};
