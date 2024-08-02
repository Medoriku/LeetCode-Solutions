class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std:: unordered_set<int> seen;
        int count = 0;

        // for each element in nums vector
        for (int num:nums){
            // If num is not found in the seen set
            if (seen.find(num) == seen.end()){
                // Add the current element to seen set
                seen.insert(num);
                // Increase the count of unique elements
                nums[count++] = num;
            }
        }
        return count;
    }
};