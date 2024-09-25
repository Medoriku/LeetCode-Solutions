#include <vector>
#include <algorithm> // For sorting
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Avoid duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Use two pointers to find the other two elements
            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Avoid duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    // Move the pointers
                    ++left;
                    --right;
                } else if (sum < target) {
                    // Move the left pointer to increase the sum
                    ++left;
                } else {
                    // Move the right pointer to decrease the sum
                    --right;
                }
            }
        }
        
        return result;
    }
};
