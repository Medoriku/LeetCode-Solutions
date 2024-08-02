class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        // for every element in nums vector
        for(int i = 0; i < nums.size(); ++i){
            // if the element does not equal val
            if(nums[i] != val){
                // place the element at the current position of count
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};