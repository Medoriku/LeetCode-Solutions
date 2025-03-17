class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count occurrences of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Check if all frequencies are even
        for (auto& entry : freq) {
            if (entry.second % 2 != 0)
                return false;
        }

        return true;
    }
};
