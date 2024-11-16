#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results;

        for (int i = 0; i <= n - k; i++) {
            bool isConsecutive = true;

            // Check if the subarray nums[i..(i+k-1)] is consecutive and sorted
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j + 1] - nums[j] != 1) {
                    isConsecutive = false;
                    break;
                }
            }

            if (isConsecutive) {
                results.push_back(nums[i + k - 1]); // Maximum of a sorted, consecutive subarray is the last element
            } else {
                results.push_back(-1);
            }
        }

        return results;
    }
};
