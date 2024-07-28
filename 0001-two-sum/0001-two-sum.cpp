class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Loop through the elements of the vector
        for (int i = 0; i != nums.size(); ++i){
            // Loop through the elements of the vector excluding the i and elements before i
            for (int j = i + 1; j != nums.size(); ++j){
                // If the sum of the element of the vector with the index i and element of the vector with the index j equal the target integer, return the indices of those elements
                if (nums[i] + nums[j] == target){
                    return {i, j};
                } 
            }
        }
        return {};
    }
};