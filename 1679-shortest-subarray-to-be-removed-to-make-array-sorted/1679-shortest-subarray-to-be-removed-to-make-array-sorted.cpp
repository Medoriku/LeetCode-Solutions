
class Solution {
public:
    int findLengthOfShortestSubarray(std::vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Find the longest non-decreasing prefix
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        if (left == n - 1) return 0; // The array is already sorted

        // Step 2: Find the longest non-decreasing suffix
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }

        // Step 3: Calculate the minimum length to remove
        int result = std::min(n - left - 1, right); // Removing middle part or from one side

        // Step 4: Try merging prefix and suffix
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = std::min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};
