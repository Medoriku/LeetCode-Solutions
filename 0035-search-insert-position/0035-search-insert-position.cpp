class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        // Case when target is less than the first element
        if (target < nums[0]){
            return 0;
        }

        //Case when target is larger than the last element
        if (target > nums[size - 1]){
            return size;
        }

        //Case when target is in the range from the first to last element
        for (int i = 0; i < (size); i++){
            if (target == nums[i]){
                return i;
            }
            else if (target > nums[i] && target < nums[i+1]){
                return i+1;
            }
        }
        return -1;
    }
};